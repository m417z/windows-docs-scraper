# SetupGetInfDriverStoreLocationA function

## Description

The **SetupGetInfDriverStoreLocation** function retrieves the fully qualified file name (directory path and file name) of an [INF file](https://learn.microsoft.com/windows-hardware/drivers/install/overview-of-inf-files) in the driver store that corresponds to a specified INF file in the system INF file directory or a specified INF file in the driver store.

## Parameters

### `FileName` [in]

A pointer to a NULL-terminated string that contains the name, and optionally the full directory path, of an INF file in the system INF file directory. Alternatively, this parameter is a pointer to a NULL-terminated string that contains the fully qualified file name (directory path and file name) of an INF file in the driver store.

For more information about how to specify the INF file, see the following **Remarks** section.

### `AlternatePlatformInfo` [in, optional]

Reserved for system use.

### `LocaleName` [in, optional]

Reserved for system use.

### `ReturnBuffer` [out]

A pointer to a buffer in which the function returns a NULL-terminated string that contains the fully qualified file name of the specified INF file. This parameter can be set to **NULL**. The maximum supported path size is MAX_PATH. For information about how to determine the required size of the buffer, see the following **Remarks** section.

### `ReturnBufferSize` [in]

The size, in characters, of the buffer supplied by *ReturnBuffer*.

### `RequiredSize` [out, optional]

A pointer to a DWORD-typed variable that receives the size, in characters, of the *ReturnBuffer* buffer. This parameter is optional and can be set to **NULL**.

## Return value

If **SetupGetInfDriverStoreLocation** succeeds, the function returns **TRUE**; otherwise, the function returns **FALSE**. To obtain extended error information, call [GetLastError](https://learn.microsoft.com/windows/win32/api/errhandlingapi/nf-errhandlingapi-getlasterror).

If the size, in characters, of the fully qualified file name of the requested INF file, including a null-terminator, is greater than *ReturnBufferSize*, the function will fail, and a call to [GetLastError](https://learn.microsoft.com/windows/win32/api/errhandlingapi/nf-errhandlingapi-getlasterror) will return ERROR_INSUFFICIENT_BUFFER.

## Remarks

To determine the size of the return buffer that is required to contain the fully qualified file name of the specified INF file in the driver store, call **SetupGetInfDriverStoreLocation** and set *ReturnBuffer* to **NULL**, *ReturnBufferSize* to zero, and supply *RequiredSize*. **SetupGetInfDriverStoreLocation** will return the required buffer size in *RequiredSize*.

When device installation preinstalls a [driver package](https://learn.microsoft.com/windows-hardware/drivers/install/difx-guidelines) in the driver store, it creates two copies of the driver package INF file. Device installation installs one copy in the system INF directory and assigns that copy of the INF file a unique *published file name* of the form *OEMnnn.inf*. Device installation installs a second copy of the INF file in the driver store and assigns that copy the original INF file name.

**SetupGetInfDriverStoreLocation** returns the fully qualified file name of the INF file in the driver store that matches the INF file, if any, that is supplied by *FileName*. *Filename* must specify the file name, and optionally the directory path, of an INF file in the system INF directory. Alternatively, *Filename* must specify the fully qualified file name of an INF file in the driver store.

For example, assume that the INF file for a driver package is *Myinf.inf*, and that for this driver package, device installation installs the INF file *OEM1.inf* in the system INF directory C:*\Windows\inf.* Further assume that device installation installs the corresponding INF file copy C:*\windows\system32\driverstore\filerepository\myinf_12345678\myinf.inf* in the driver store. In this case, the function returns C:*\windows\system32\driverstore\filerepository\myinf_12345678\myinf.inf* if *FileName* supplies one of the following strings: *OEM1.inf*, C:*\Windows\inf\OEM1.inf*, or C:*\windows\system32\driverstore\filerepository\myinf_12345678\myinf.inf.*

[Class installers](https://learn.microsoft.com/windows-hardware/drivers/) and [co-installers](https://learn.microsoft.com/windows-hardware/drivers/) can use **SetupGetInfDriverStoreLocation** to access files in a [driver package](https://learn.microsoft.com/windows-hardware/drivers/install/difx-guidelines) that is preinstalled in the driver store. To determine the path of the driver package in the driver store, the installer does the following:

1. Call [SetupDiGetDriverInfoDetail](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupdigetdriverinfodetaila) to retrieve a [SP_DRVINFO_DETAIL_DATA](https://learn.microsoft.com/windows/desktop/api/setupapi/ns-setupapi-sp_drvinfo_detail_data_a) structure for a driver. The **InfFileName** member of this structure contains the fully qualified file name of the driver INF file in the system INF directory.
2. Call **SetupGetInfDriverStoreLocation** and supply the fully qualified file name of the driver INF file that was retrieved by calling **SetupDiGetDriverInfoDetail**. **SetupGetInfDriverStoreLocation** will return the fully qualified file name of the driver INF file in the driver store. The directory path part of the fully qualified file name of the INF file is the path of the [driver package](https://learn.microsoft.com/windows-hardware/drivers/install/difx-guidelines) files.

**Note** **SetupGetInfDriverStoreLocation** does not process the contents of the INF file that is specified in *FileName*. You cannot use this function to perform a content-specific search for an INF file in the driver store.

Call the [SetupGetInfPublishedName](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupgetinfpublishednamea) function to retrieve the fully qualified file name of an [INF file](https://learn.microsoft.com/windows-hardware/drivers/install/overview-of-inf-files) in the system INF file directory that corresponds to a specified INF file in the system INF file directory or a specified file in the driver store.

> [!NOTE]
> The setupapi.h header defines SetupGetInfDriverStoreLocation as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[SP_ALTPLATFORM_INFO](https://learn.microsoft.com/windows/win32/api/setupapi/ns-setupapi-sp_altplatform_info_v2)

[SP_DRVINFO_DETAIL_DATA](https://learn.microsoft.com/windows/desktop/api/setupapi/ns-setupapi-sp_drvinfo_detail_data_a)

[SetupDiGetDriverInfoDetail](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupdigetdriverinfodetaila)

[SetupGetInfPublishedName](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupgetinfpublishednamea)