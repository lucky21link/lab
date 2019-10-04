step1:
sudo addgroup hadoop
step 2 :
sudo adduser --ingroup hadoop hduser
=====================================================
step 3 : 
sudo adduser hduser sudo
=====================================================
step 4 : 
 sudo apt-get install ssh
=====================================================
step 5 : 
ssh-keygen -t rsa -P ""
=====================================================
step 6 : 
cat $HOME/.ssh/id_rsa.pub >> $HOME/.ssh/authorized_key
======================================================
wget https://archive.apache.org/dist/hadoop/core/hadoop-2.8.4/hadoop-2.8.4.tar.gz
=================================================================================
step 7 : 
sudo tar xvzf hadoop-2.8.4.tar.gz
==================================================================================
step 8 :
sudo mkdir –p /usr/local/hadoop
=================================================================================
step 9 : 
sudo mv hadoop-2.8.4 /usr/local/hadoop
==================================================================================
step 10 : 
sudo chown –R hduser:hadoop /usr/local/hadoop
==================================================================================
step 11 : 
 \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\

step 12: 
cd /usr/local/hadoop/hadoop-2.8.4/etc/hadoop
====================================================================================
step 13 : 
sudo nano hadoop-env.sh
{
	hadoop-env.sh contains the environment variables that are used in the script to run Hadoop like Java home path
}
	export JAVA_HOME={path///////////////}
===================================================================
step 14 : 
sudo mkdir -p /usr/local/hadoop_tmp/hdfs/namenode
============================================================
step 15 : 
sudo mkdir -p /usr/local/hadoop_tmp/hdfs/datanode
================================================================
step 16 : 
sudo chown -R hduser:hadoop /usr/local/hadoop_tmp
===========================================================================
step 17 : 
sudo nano hdfs-site.xml
{
	<property>
	<name>dfs.replication</name>
	<value>1</value>
	</property>
	<property>
	<name>dfs.namenode.name.dir</name>
	<value>file:/usr/local/hadoop_tmp/hdfs/namenode</value>
	</property>
	<property>
	<name>dfs.datanode.data.dir</name>
	<value>file:/usr/local/hadoop_tmp/hdfs/datanode</value>
	</property>
}
===========================================================================
step 18 :
sudo nano core-site.xml
{
	<property>
	<name>fs.default.name</name>
	<value>hdfs://localhost:8088</value>
	</property>
}
============================================================================
step 19: 
sudo nano yarn-site.xml
{
	<property>
	<name>yarn.nodemanager.aux-services</name>
	<value>mapreduce_shuffle</value>
	</property>
	<property>
	<name>yarn.nodemanager.aux-services.mapreduce.shuffle.class<name>
	<value>org.apache.hadoop.mapred.Shuffle-Handler</value>
	</property
}
===================================================================
step 20 : 
cp /usr/local/hadoop/hadoop-2.8.4/etc/hadoop/mapred-site.xml.template /usr/local/hadoop/hadoop-2.8.4/etc/hadoop/mapred-site.xml
==========================================================================
step 21 : 
sudo nano mapred-site.xml
{
	<property>
	<name>mapreduce.framework.name</name>
	<value>yarn</value>
	</property>
}
======================================================================================
step 22 : 
su hduser 
==================================================================================================
step 23  :
cd  /usr/local/hadoop/hadoop-2.8.4/bin
bin/hadoop namenode -format
======================================================================================
step 24: 
cd /usr/local/hadoop/hadoop-2.8.4/sbin
sh start-dfs.sh
jps	
=======================================================================================
step 25: 
localhost:8088
============================================================================================
step:26
localhost:50070
==============================================================================================
step 27 : 
stop-dfs.sh
===================================
step 28 : 
stop-yarn.sh







		ex2 :MOUNT THE ONE NODE HADOOP CLUSTER USING FUSE


step1 : 
su hduser
=====================================
step 2: 
cd /usr/local/hadoop/hadoop-2.8.4/sbin
===================================
step 3: 
start-dfs.sh
======================================\
step 4 :
start-yarn.sh
===========================================
step 5 : 
 jps
=============================================
step 6;
wget http://archive.cloudera.com/cdh5/one-click-install/trusty/amd64/cdh5-repository_1.0_all.deb
==============================================
step: 7
sudo dpkg -i cdh5-repository_1.0_all.deb  
===========================================================
step 8 : 
sudo apt-get update
==============================================================
step 9: 
 sudo apt-get install hadoop-hdfs-fuse
==========================================================
step 10 ; 
sudo mkdir -p file
==============================================================
step 11: 
sudo hadoop-fuse-dfs dfs://localhost:9000file
