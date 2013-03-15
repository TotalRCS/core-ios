//
//  RcsIOSUsbSupport.h
//  RCSUSBInstaller
//
//  Created by armored on 2/7/13.
//  Copyright (c) 2013 armored. All rights reserved.
//
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/types.h>
//#include <sys/uio.h>
#include <unistd.h>
#include <dirent.h>
#include <string.h>

#include <libimobiledevice/libimobiledevice.h>
#include <libimobiledevice/lockdown.h>
#include <libimobiledevice/afc.h>
#include <libimobiledevice/diagnostics_relay.h>

#ifndef RCSUSBInstaller_RcsIOSUsbSupport_h
#define RCSUSBInstaller_RcsIOSUsbSupport_h

int  restart_device();
int  isDeviceAttached();
int  remove_installation();
int  check_installation(int sec, int max_repeat);

char *get_model();
char *get_version();
void get_device_info(afc_client_t afc);
void close_device(afc_client_t afc);

char** list_dir_content(char *dir_name);

afc_client_t open_device();
idevice_error_t make_install_directory();
idevice_error_t create_launchd_plist();
idevice_error_t copy_install_files(char *lpath, char **dir_content);
idevice_error_t copy_local_file(afc_client_t afc, char *lpath, char* lsrc);
idevice_error_t copy_buffer_file(char *filebuff, int filelen, char* filename);

#endif
