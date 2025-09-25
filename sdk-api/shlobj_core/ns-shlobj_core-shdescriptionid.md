# SHDESCRIPTIONID structure

## Description

Receives item data in response to a call to [SHGetDataFromIDList](https://learn.microsoft.com/windows/desktop/api/shlobj_core/nf-shlobj_core-shgetdatafromidlista).

## Members

### `dwDescriptionId`

Type: **DWORD**

Receives a value that determines what type the item is. One of the following values.

#### SHDID_ROOT_REGITEM

The item is a registered item on the desktop.

#### SHDID_FS_FILE

The item is a file.

#### SHDID_FS_DIRECTORY

The item is a folder.

#### SHDID_FS_OTHER

The item is an unidentified item in the file system.

#### SHDID_COMPUTER_DRIVE35

The item is a 3.5-inch floppy drive.

#### SHDID_COMPUTER_DRIVE525

The item is a 5.25-inch floppy drive.

#### SHDID_COMPUTER_REMOVABLE

The item is a removable disk.

#### SHDID_COMPUTER_FIXED

The item is a fixed hard disk.

#### SHDID_COMPUTER_NETDRIVE

The item is a drive that is mapped to a network share.

#### SHDID_COMPUTER_CDROM

The item is a CD-ROM drive.

#### SHDID_COMPUTER_RAMDISK

The item is a RAM disk.

#### SHDID_COMPUTER_OTHER

The item is an unidentified system device.

#### SHDID_NET_DOMAIN

The item is a network domain.

#### SHDID_NET_SERVER

The item is a network server.

#### SHDID_NET_SHARE

The item is a network share.

#### SHDID_NET_RESTOFNET

Not currently used.

#### SHDID_NET_OTHER

The item is an unidentified network resource.

#### SHDID_COMPUTER_IMAGING

**Windows XP and later**. Not currently used.

#### SHDID_COMPUTER_AUDIO

**Windows XP and later**. Not currently used.

#### SHDID_COMPUTER_SHAREDDOCS

**Windows XP and later**. The item is the system shared documents folder.

#### SHDID_MOBILE_DEVICE

**Windows Vista and later.** The item is a mobile device, such as a personal digital assistant (PDA).

### `clsid`

Type: **CLSID**

Receives the CLSID of the object to which the item belongs.