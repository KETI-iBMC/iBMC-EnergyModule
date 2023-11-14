#!/bin/sh

cd ..

./testbuild.sh

#BMCIP=10.0.4.144
# CMMIP=1.215.235.250

#ID=root
#PASSWD=ketilinux
#FPATH=/usr/sbin
#FNAME=KETI-EMM

#ssh-keygen -f "/root/.ssh/known_hosts" -R "${BMCIP}"
#ssh-keyscan -t rsa ${BMCIP} >>~/.ssh/known_hosts

#cmake CMakeLists.txt
#make -j 60
#cp keti-redfish ../overlay/${FPATH}

#sshpass -p ${PASSWD} scp ./src/${FNAME} ${ID}@${BMCIP}:${FPATH}

#scp ${FNAME} ${ID}@${CMMIP}:${FPATH}
