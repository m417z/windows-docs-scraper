# _FLT_FILE_NAME_INFORMATION structure

## Description

The FLT_FILE_NAME_INFORMATION structure contains file name information.

## Members

### `Size`

Size, in bytes, of the FLT_FILE_NAME_INFORMATION structure.

### `NamesParsed`

Bitmask of flags that indicate which name components have been parsed from the **Name** string by [FltParseFileNameInformation](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltparsefilenameinformation). Note that, when parsing the **Name** string, **FltParseFileNameInformation** sets this flag for each component, whether the component is found to be present in the string. These values may be combined by using the OR operator.

| Flag | Component |
| --- | --- |
| FLTFL_FILE_NAME_PARSED_FINAL_COMPONENT | **FinalComponent** |
| FLTFL_FILE_NAME_PARSED_EXTENSION | **Extension** |
| FLTFL_FILE_NAME_PARSED_STREAM | **Stream** |
| FLTFL_FILE_NAME_PARSED_PARENT_DIR | **ParentDir** |

### `Format`

Format of the name information stored in the **Name** member. This member can be one of the following values. (For an explanation of these formats, see the following Remarks section.)

| Value | Meaning |
| --- | --- |
| FLT_FILE_NAME_NORMALIZED | The **Name** member contains the normalized name for the file. |
| FLT_FILE_NAME_OPENED | The **Name** member contains the name that was used when the file was opened. This name string is not normalized. |
| FLT_FILE_NAME_SHORT | The **Name** member contains the short (8.3) name for the file. The short name for a file does not include the volume name, directory path, or stream name. This name string is not normalized. |

### `Name`

[UNICODE_STRING](https://learn.microsoft.com/windows/win32/api/ntdef/ns-ntdef-_unicode_string) structure that contains the file name string, formatted as specified by the **Format** member.

### `Volume`

UNICODE_STRING structure that contains the volume name parsed from the **Name** string. If **Format** is FLT_FILE_NAME_SHORT, **Volume.Length** is zero.

### `Share`

UNICODE_STRING structure that contains the network share name parsed from the **Name** string for a remote file. If **Format** is FLT_FILE_NAME_SHORT, **Share.Length** is zero.

### `Extension`

UNICODE_STRING structure that contains the extension parsed from the **Name** string. If no extension is found, [FltParseFileNameInformation](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltparsefilenameinformation) sets **Extension.Length** to zero.

### `Stream`

UNICODE_STRING structure that contains the stream name parsed from the **Name** string. If no stream name is found, or if **Format** is FLT_FILE_NAME_SHORT, [FltParseFileNameInformation](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltparsefilenameinformation) sets **Stream.Length** to zero.

### `FinalComponent`

UNICODE_STRING structure that contains the final name component parsed from the **Name** string. If no final component name is found, or if **Format** is FLT_FILE_NAME_SHORT, [FltParseFileNameInformation](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltparsefilenameinformation) sets **FinalComponent.Length** to zero.

### `ParentDir`

UNICODE_STRING structure that contains the parent directory name parsed from the **Name** string by [FltParseFileNameInformation](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltparsefilenameinformation). If no parent directory name is found, or if **Format** is FLT_FILE_NAME_SHORT, **FltParseFileNameInformation** sets **ParentDir.Length** to zero.

## Remarks

The **Name** member contains one of the following:

* The normalized name for the file
* The opened name for the file
* The short name for the file

A file name is considered *normalized* if all of the following are true:

* It contains the full directory path for the file, including the volume name, unless the user opened the file by file ID but does not have traverse privilege for the entire path. (For more information, see [FltGetFileNameInformation](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltgetfilenameinformation).)
* The volume name is the volume's nonpersistent device object name (for example, "\Device\HarddiskVolume1").
* All short names are expanded to the equivalent long names.
* Any trailing ":$DATA" or "::$DATA" strings are removed from the stream name.
* All mount points are resolved.

The following is an example of a normalized file name for a local file:

```
\Device\HarddiskVolume1\Documents and Settings\MyUser\My Documents\Test Results.txt:stream1
```

The following is an example of a normalized file name for a remote file:

```
\Device\LanManRedirector\MyServer\MyShare\Documents and Settings\MyUser\My Documents\Test Results.txt:stream1
```

The *opened name* for a file is the name that was used when the file was opened. Like the normalized name, it contains the full directory path for the file, including the volume name. It differs from the normalized name in the following ways:

* The directory path for the file can contain short names as well as long names.
* Trailing ":$DATA" and "::$DATA" strings are not removed from the stream name.
* Mount points are not resolved.

The following is an example of an opened file name for a local file:

```
\Device\HarddiskVolume1\Docume~1\MyUser\MYDOCU~1\Test Results.txt:stream1:$DATA
```

The following is an example of an opened file name for a remote file:

```
\Device\LanManRedirector\MyServer\MyShare\Documents and Settings\MyUser\My Documents\Test Results.txt:stream1
```

The *short name* for a file is the short (8.3) name for the final component of the file name. Because it is generated when the file is opened, the short name is not available for an unopened file object, and it is not available in the create dispatch ("pre-create") path. It is also not available for NTFS stream file objects. Not all open files have short file names. For example, on NTFS partitions where short file name generation has been disabled, no files have short file names.

The following is an example of a short name for a file:

```
TestRe~1.txt
```

To obtain an FLT_FILE_NAME_INFORMATION structure for a file, call [FltGetFileNameInformation](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltgetfilenameinformation), [FltGetFileNameInformationUnsafe](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltgetfilenameinformationunsafe), or [FltGetDestinationFileNameInformation](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltgetdestinationfilenameinformation). These routines returns a pointer to a Filter Manager-owned FLT_FILE_NAME_INFORMATION structure that is shared by all minifilters.

**Note** Do not modify the contents of FLT_FILE_NAME_INFORMATION structures, because these structures are cached by the Filter Manager so that all minifilters can use them. If your minifilter must modify this information in some way, it should copy the information into another buffer first.

File systems such as NTFS and FAT use a per-volume tunnel cache to briefly preserve file names and other metadata for files that are being renamed, linked to, or deleted. This file name tunneling can cause the final component in normalized file name information returned by a preoperation call to [FltGetFileNameInformation](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltgetfilenameinformation), [FltGetFileNameInformationUnsafe](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltgetfilenameinformationunsafe), or [FltGetDestinationFileNameInformation](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltgetdestinationfilenameinformation) to be invalidated. If a minifilter retrieves normalized file name information in the preoperation callback ([PFLT_PRE_OPERATION_CALLBACK](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nc-fltkernel-pflt_pre_operation_callback)) routine for a create, hard-link, or rename operation, it must call [FltGetTunneledName](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltgettunneledname) from its postoperation callback ([PFLT_POST_OPERATION_CALLBACK](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nc-fltkernel-pflt_post_operation_callback)) routine to retrieve the correct file name information for the file.

Although it contains numerous [UNICODE_STRING](https://learn.microsoft.com/windows/win32/api/ntdef/ns-ntdef-_unicode_string) structures, the FLT_FILE_NAME_INFORMATION structure does not occupy much space in memory because all of the UNICODE_STRING structures in a FLT_FILE_NAME_INFORMATION structure share a single buffer.

To parse the contents of the **Name** string, call [FltParseFileNameInformation](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltparsefilenameinformation). This routine sets the values of the **Extension**, **Stream**, **FinalComponent**, **ParentDir**, and **NamesParsed** members of this structure.

Minifilters are responsible for calling [FltReleaseFileNameInformation](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltreleasefilenameinformation) to release the FLT_FILE_NAME_INFORMATION structure when it is no longer needed.

## See also

[FLT_FILE_NAME_OPTIONS](https://learn.microsoft.com/windows-hardware/drivers/ifs/flt-file-name-options)

[FltGetDestinationFileNameInformation](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltgetdestinationfilenameinformation)

[FltGetFileNameInformation](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltgetfilenameinformation)

[FltGetFileNameInformationUnsafe](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltgetfilenameinformationunsafe)

[FltGetTunneledName](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltgettunneledname)

[FltParseFileName](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltparsefilename)

[FltParseFileNameInformation](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltparsefilenameinformation)

[FltReferenceFileNameInformation](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltreferencefilenameinformation)

[FltReleaseFileNameInformation](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltreleasefilenameinformation)

[PFLT_POST_OPERATION_CALLBACK](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nc-fltkernel-pflt_post_operation_callback)

[PFLT_PRE_OPERATION_CALLBACK](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nc-fltkernel-pflt_pre_operation_callback)

[UNICODE_STRING](https://learn.microsoft.com/windows/win32/api/ntdef/ns-ntdef-_unicode_string)