# FLT_FILESYSTEM_TYPE enumeration

## Description

The **FLT_FILESYSTEM_TYPE** enumeration identifies the type of file system being used on a volume.

## Constants

### `FLT_FSTYPE_UNKNOWN`

Unknown file system type.

### `FLT_FSTYPE_RAW`

Microsoft RAW file system. File system namespace: \FileSystem\RAW.

### `FLT_FSTYPE_NTFS`

Microsoft NTFS file system. File system namespace: \FileSystem\Ntfs.

### `FLT_FSTYPE_FAT`

Microsoft FAT file system. File system namespace: \FileSystem\Fastfat.

### `FLT_FSTYPE_CDFS`

Microsoft CDFS file system. File system namespace: \FileSystem\Cdfs.

### `FLT_FSTYPE_UDFS`

Microsoft UDFS file system. File system namespace: \FileSystem\Udfs.

### `FLT_FSTYPE_LANMAN`

Microsoft LanMan Redirector. File system namespace: \FileSystem\MRxSmb.

### `FLT_FSTYPE_WEBDAV`

Microsoft WebDav redirector. File system namespace: \FileSystem\MRxDav.

### `FLT_FSTYPE_RDPDR`

Microsoft Terminal Server redirector. File system namespace: \Driver\rdpdr.

### `FLT_FSTYPE_NFS`

Microsoft NFS file system. File system namespace: \FileSystem\NfsRdr.

### `FLT_FSTYPE_MS_NETWARE`

Microsoft NetWare redirector. File system namespace: \FileSystem\nwrdr.

### `FLT_FSTYPE_NETWARE`

Novell NetWare redirector.

### `FLT_FSTYPE_BSUDF`

The BsUDF CD-ROM driver. File system namespace: \FileSystem\BsUDF.

### `FLT_FSTYPE_MUP`

Microsoft MUP redirector. File system namespace: \FileSystem\Mup.

### `FLT_FSTYPE_RSFX`

Microsoft WinFS redirector. File system namespace: \FileSystem\RsFxDrv.

### `FLT_FSTYPE_ROXIO_UDF1`

Roxio UDF writeable file system. File system namespace: \FileSystem\cdudf_xp.

### `FLT_FSTYPE_ROXIO_UDF2`

Roxio UDF readable file system. File system namespace: \FileSystem\UdfReadr_xp.

### `FLT_FSTYPE_ROXIO_UDF3`

Roxio DVD file system. File system namespace: \FileSystem\DVDVRRdr_xp.

### `FLT_FSTYPE_TACIT`

Tacit file system. Namespace: \Device\TCFSPSE.

### `FLT_FSTYPE_FS_REC`

Microsoft file system recognizer. File system namespace: \FileSystem\Fs_rec.

### `FLT_FSTYPE_INCD`

Nero InCD file system. File system namespace: \FileSystem\InCDfs.

### `FLT_FSTYPE_INCD_FAT`

Nero InCD FAT file system. File system namespace: \FileSystem\InCDFat.

### `FLT_FSTYPE_EXFAT`

Microsoft EXFat file system. File system namespace: \FileSystem\exfat.

### `FLT_FSTYPE_PSFS`

PolyServ file system. File system namespace: \FileSystem\psfs.

### `FLT_FSTYPE_GPFS`

IBM General Parallel File System. File system namespace: \FileSystem\gpfs.

### `FLT_FSTYPE_NPFS`

Microsoft named pipe file system. File system namespace: \FileSystem\npfs.

### `FLT_FSTYPE_MSFS`

Microsoft mailslot file system. File system namespace: \FileSystem\msfs.

### `FLT_FSTYPE_CSVFS`

Microsoft cluster shared volume file system. File system namespace: \FileSystem\csvfs.

### `FLT_FSTYPE_REFS`

Microsoft ReFS file system. File system namespace: \FileSystem\refs.

### `FLT_FSTYPE_OPENAFS`

 OpenAFS file system. File system namespace: \FileSystem\AFSRedirector.

### `FLT_FSTYPE_CIMFS`

Microsoft Composite Image file system. File system namespace: \FileSystem\cimfs.

## Remarks

New file systems that are not part of the **FLT_FILESYSTEM_TYPE** enumeration are treated as **FLT_FSTYPE_UNKNOWN**.

## See also

[**FILTER_VOLUME_STANDARD_INFORMATION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltuserstructures/ns-fltuserstructures-_filter_volume_standard_information)

[**FltGetFileSystemType**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltgetfilesystemtype)

[**INSTANCE_AGGREGATE_STANDARD_INFORMATION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltuserstructures/ns-fltuserstructures-_instance_aggregate_standard_information)

[**PFLT_INSTANCE_SETUP_CALLBACK**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nc-fltkernel-pflt_instance_setup_callback)