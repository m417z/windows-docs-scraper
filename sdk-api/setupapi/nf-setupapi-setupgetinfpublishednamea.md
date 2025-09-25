# SetupGetInfPublishedNameA function

## Description

The **SetupGetInfPublishedName** function retrieves the fully qualified file name (directory path and file name) of an [INF file](https://learn.microsoft.com/windows-hardware/drivers/install/overview-of-inf-files) in the system INF file directory that corresponds to a specified INF file in the driver store or a specified INF file in the system INF file directory.

## Parameters

### `DriverStoreLocation` [in]

A pointer to a NULL-terminated string that contains the fully qualified file name (directory path and file name) of an INF file in the driver store. Alternatively, this parameter is a pointer to a NULL-terminated string that contains the name, and optionally the full directory path, of an INF file in the system INF file directory. For more information about how to specify the INF file, see the following **Remarks** section.

### `ReturnBuffer` [out]

A pointer to the buffer in which **SetupGetInfPublishedName** returns a NULL-terminated string that contains the fully qualified file name of the specified INF file in the system INF directory. The maximum path size is MAX_PATH. This pointer can be set to **NULL**. For information about how to determine the required size of the return buffer, see the following **Remarks** section.

### `ReturnBufferSize` [in]

The size, in characters, of the buffer supplied by *ReturnBuffer*.

### `RequiredSize` [out, optional]

A pointer to a DWORD-typed variable that receives the size, in characters, of the *ReturnBuffer* buffer. This parameter is optional and can be set to **NULL**.

## Return value

If **SetupGetInfPublishedName** succeeds, the function returns **TRUE**; otherwise, the function returns **FALSE**. To obtain extended error information, call [GetLastError](https://learn.microsoft.com/windows/win32/api/errhandlingapi/nf-errhandlingapi-getlasterror).

If the size, in characters, of the fully qualified file name of the requested INF file, including a null-terminator, is greater than *ReturnBufferSize*, the function will fail, and a call to [GetLastError](https://learn.microsoft.com/windows/win32/api/errhandlingapi/nf-errhandlingapi-getlasterror) will return ERROR_INSUFFICIENT_BUFFER.

## Remarks

To determine the size of the return buffer that is required to contain the fully qualified file name of the specified INF file in the system INF directory, call **SetupGetInfPublishedName** and set *ReturnBuffer* to **NULL**, *ReturnBufferSize* to zero, and supply *RequiredSize*. **SetupGetInfPublishedName** will return the required buffer size in *RequiredSize*.

When device installation preinstalls a [driver package](https://learn.microsoft.com/windows-hardware/drivers/install/difx-guidelines) in the driver store, it creates two copies of the driver package INF file. Device installation adds one copy to the system INF directory and assigns that copy of the INF file a unique *published file name* of the form *OEMnnn.inf*. Device installation adds a second copy of the INF file to the driver store and assigns that copy the original INF file name.

**SetupGetInfPublishedName** returns the fully qualified file name of the INF file in the system INF file directory that matches the INF file, if any, that is supplied by *DriverStoreLocation*. *DriverStoreLocation*  must specify the fully qualified file name of an INF file in the driver store or must specify the file name, and optionally the directory path, of an INF file in the system INF directory. For example, assume that the INF file for a driver package is *myinf.inf*, and that for this driver package, device installation installs the INF file *OEM1.inf* in the system INF directory C:*\Windows\inf*. Further assume that device installation installs the corresponding INF file copy C:*\windows\system32\driverstore\filerepository\myinf_12345678\myinf.inf* in the driver store. In this case, the function returns C:*\Windows\inf\OEM1.inf* if *DriverStoreLocation* supplies one of the following strings: C:*\windows\system32\driverstore\filerepository\myinf_12345678\myinf.inf, OEM1.inf*, or C:*\Windows\inf\OEM1.inf.*

Call the [SetupGetInfDriverStoreLocation](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupgetinfdriverstorelocationa) function to retrieve the fully qualified file name of an INF file in the driver store that corresponds to a specified INF file in the system INF file directory or a specified file in the driver store.

> [!NOTE]
> The setupapi.h header defines SetupGetInfPublishedName as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[SetupGetInfDriverStoreLocation](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupgetinfdriverstorelocationa)