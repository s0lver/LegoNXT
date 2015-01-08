-- MySQL dump 10.13  Distrib 5.6.17, for Win64 (x86_64)
--
-- Host: localhost    Database: smarthouse
-- ------------------------------------------------------
-- Server version	5.6.17

/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8 */;
/*!40103 SET @OLD_TIME_ZONE=@@TIME_ZONE */;
/*!40103 SET TIME_ZONE='+00:00' */;
/*!40014 SET @OLD_UNIQUE_CHECKS=@@UNIQUE_CHECKS, UNIQUE_CHECKS=0 */;
/*!40014 SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0 */;
/*!40101 SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='NO_AUTO_VALUE_ON_ZERO' */;
/*!40111 SET @OLD_SQL_NOTES=@@SQL_NOTES, SQL_NOTES=0 */;

--
-- Table structure for table `eventos`
--

DROP TABLE IF EXISTS `eventos`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `eventos` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `idLegoRecurso` int(11) NOT NULL,
  `timestamp` datetime DEFAULT NULL,
  `sentido` tinyint(1) DEFAULT NULL,
  PRIMARY KEY (`id`),
  KEY `fk_Evento_LegosRecursos1_idx` (`idLegoRecurso`),
  CONSTRAINT `fk_Evento_LegosRecursos1` FOREIGN KEY (`idLegoRecurso`) REFERENCES `legosrecursos` (`id`) ON DELETE NO ACTION ON UPDATE NO ACTION
) ENGINE=InnoDB AUTO_INCREMENT=677 DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;


--
-- Table structure for table `horarios`
--

DROP TABLE IF EXISTS `horarios`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `horarios` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `horaInicio` time NOT NULL,
  `horaFin` time NOT NULL,
  `idLegoRecurso` int(11) NOT NULL,
  PRIMARY KEY (`id`),
  KEY `fk_Horarios_LegosRecursos1_idx` (`idLegoRecurso`),
  CONSTRAINT `fk_Horarios_LegosRecursos1` FOREIGN KEY (`idLegoRecurso`) REFERENCES `legosrecursos` (`id`) ON DELETE NO ACTION ON UPDATE NO ACTION
) ENGINE=InnoDB AUTO_INCREMENT=9 DEFAULT CHARSET=utf8 COMMENT='	';
/*!40101 SET character_set_client = @saved_cs_client */;


--
-- Table structure for table `legos`
--

DROP TABLE IF EXISTS `legos`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `legos` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `mac` varchar(12) NOT NULL,
  `idTipoLego` int(11) NOT NULL,
  PRIMARY KEY (`id`),
  KEY `fk_Legos_TiposLego_idx` (`idTipoLego`),
  CONSTRAINT `fk_Legos_TiposLego` FOREIGN KEY (`idTipoLego`) REFERENCES `tiposlego` (`id`) ON DELETE NO ACTION ON UPDATE NO ACTION
) ENGINE=InnoDB AUTO_INCREMENT=5 DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;


--
-- Table structure for table `legosrecursos`
--

DROP TABLE IF EXISTS `legosrecursos`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `legosrecursos` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `idLego` int(11) NOT NULL,
  `idRecurso` int(11) NOT NULL,
  PRIMARY KEY (`id`),
  KEY `fk_LegosRecursos_Legos1_idx` (`idLego`),
  KEY `fk_LegosRecursos_Recursos1_idx` (`idRecurso`),
  CONSTRAINT `fk_LegosRecursos_Legos1` FOREIGN KEY (`idLego`) REFERENCES `legos` (`id`) ON DELETE NO ACTION ON UPDATE NO ACTION,
  CONSTRAINT `fk_LegosRecursos_Recursos1` FOREIGN KEY (`idRecurso`) REFERENCES `recursos` (`id`) ON DELETE NO ACTION ON UPDATE NO ACTION
) ENGINE=InnoDB AUTO_INCREMENT=9 DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `legosrecursos`
--

LOCK TABLES `legosrecursos` WRITE;
/*!40000 ALTER TABLE `legosrecursos` DISABLE KEYS */;
INSERT INTO `legosrecursos` VALUES (1,1,3),(2,1,4),(5,3,1),(6,3,2),(7,4,5),(8,4,8);
/*!40000 ALTER TABLE `legosrecursos` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `recursos`
--

DROP TABLE IF EXISTS `recursos`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `recursos` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `descripcion` varchar(45) NOT NULL,
  `conHorario` tinyint(1) NOT NULL,
  `idTipoLego` int(11) NOT NULL,
  PRIMARY KEY (`id`),
  KEY `fk_Recursos_TiposLego1_idx` (`idTipoLego`),
  CONSTRAINT `fk_Recursos_TiposLego1` FOREIGN KEY (`idTipoLego`) REFERENCES `tiposlego` (`id`) ON DELETE NO ACTION ON UPDATE NO ACTION
) ENGINE=InnoDB AUTO_INCREMENT=9 DEFAULT CHARSET=utf8 COMMENT='					';
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `recursos`
--

LOCK TABLES `recursos` WRITE;
/*!40000 ALTER TABLE `recursos` DISABLE KEYS */;
INSERT INTO `recursos` VALUES (1,'Ventana',1,1),(2,'Persiana',1,1),(3,'Luces',1,2),(4,'Aire acondicionado',1,2),(5,'Puerta',1,3),(8,'Alarma',0,3);
/*!40000 ALTER TABLE `recursos` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `tiposlego`
--

DROP TABLE IF EXISTS `tiposlego`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `tiposlego` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `descripcion` varchar(45) NOT NULL,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB AUTO_INCREMENT=4 DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `tiposlego`
--

LOCK TABLES `tiposlego` WRITE;
/*!40000 ALTER TABLE `tiposlego` DISABLE KEYS */;
INSERT INTO `tiposlego` VALUES (1,'Controlador de ventanas y persianas'),(2,'Controlador de luces y aire acondicionado'),(3,'Controlador de puerta de acceso');
/*!40000 ALTER TABLE `tiposlego` ENABLE KEYS */;
UNLOCK TABLES;
/*!40103 SET TIME_ZONE=@OLD_TIME_ZONE */;

/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES */;

-- Dump completed on 2014-12-18 12:53:24
