# FltParseFileNameInformation function

## Description

**FltParseFileNameInformation** parses the contents of a [FLT_FILE_NAME_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/ns-fltkernel-_flt_file_name_information) structure.

## Parameters

### `FileNameInformation` [in, out]

Pointer to an [FLT_FILE_NAME_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/ns-fltkernel-_flt_file_name_information) structure returned by a previous call to [FltGetDestinationFileNameInformation](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltgetdestinationfilenameinformation), [FltGetFileNameInformation](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltgetfilenameinformation), [FltGetFileNameInformationUnsafe](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltgetfilenameinformationunsafe), or [FltGetTunneledName](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltgettunneledname). This parameter is required and cannot be **NULL**.

## Return value

**FltParseFileNameInformation** returns STATUS_SUCCESS or an appropriate NTSTATUS error code.

## Remarks

**FltParseFileNameInformation** parses the **Name** member of a FLT_FILE_NAME_INFORMATION structure and uses the results to set the values of the **Volume**, **Share**, **Extension**, **Stream**, **FinalComponent**, **ParentDir**, and **NamesParsed** members of this structure. For more information, see [FLT_FILE_NAME_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/ns-fltkernel-_flt_file_name_information).

The following is an example of a normalized name for a remote file:

```
\Device\LanManRedirector\MyServer\MyShare\Documents and Settings\MyUser\My Documents\Test Results.txt:stream1
```

**FltParseFileNameInformation** parses this normalized name as follows:

**Volume**: "\Device\LanManRedirector"

**Share**: "\MyServer\MyShare"

**Extension**: "txt"

**Stream**: ":stream1"

**FinalComponent**: "Test Results.txt:stream1"

**ParentDir**: "\Documents and Settings\MyUser\My Documents\"

The following is an example of an opened name for a local file:

```
\Device\HarddiskVolume1\Docume~1\MyUser\My Documents\TestRe~1.txt:stream1:$DATA
```

**FltParseFileNameInformation** parses this opened name as follows:

**Volume**: "\Device\HarddiskVolume1"

**Share**: **NULL**

**Extension**: "txt"

**Stream**: ":stream1:$DATA"

**FinalComponent**: "TestRe~1.txt:stream1:$DATA"

**ParentDir**: "\Docume~1\MyUser\My Documents\"

The following is an example of a short name for a file:

```
TestRe~1.txt
```

**FltParseFileNameInformation** parses this short name as follows:

**Volume**: **NULL**

**Share**: **NULL**

**Extension**: "txt"

**Stream**: **NULL**

**FinalComponent**: "TestRe~1.txt"

**ParentDir**: **NULL**

The caller must not modify the contents of the *FileNameInformation* structure, because the Filter Manager caches this structure so that all minifilter drivers can use it.

**Note** If the caller is trying to parse a string, not an FLT_FILE_NAME_INFORMATION structure, use the [FltParseFileName](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltparsefilename) routine instead of **FltParseFileNameInformation**.

## See also

[FLT_FILE_NAME_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/ns-fltkernel-_flt_file_name_information)

[FltGetDestinationFileNameInformation](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltgetdestinationfilenameinformation)

[FltGetFileNameInformation](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltgetfilenameinformation)

[FltGetFileNameInformationUnsafe](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltgetfilenameinformationunsafe)

[FltGetTunneledName](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltgettunneledname)

[FltParseFileName](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltparsefilename)