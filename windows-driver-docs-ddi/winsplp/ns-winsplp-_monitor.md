## Description

> [!CAUTION]
> The **MONITOR** structure is obsolete and is supported only for compatibility reasons. New print monitors should implement [**MONITOR2**](https://learn.microsoft.com/windows-hardware/drivers/ddi/winsplp/ns-winsplp-_monitor2) so that they can be used with print server clusters.

The **MONITOR** structure contains pointers to the functions defined by print monitors.

## Members

### `pfnEnumPorts`

A port monitor server DLL's **EnumPorts** function enumerates the ports that the port monitor supports.

### `pfnOpenPort`

Pointer to the print monitor's [OpenPort](https://learn.microsoft.com/windows-hardware/drivers/ddi/winsplp/nf-winsplp-openport) function.

### `pfnOpenPortEx`

A language monitor's `OpenPortEx` function opens a printer port.

### `pfnStartDocPort`

A print monitor's `StartDocPort` function performs the tasks required to start a print job on the specified port.

### `pfnWritePort`

Pointer to the print monitor's [WritePort](https://learn.microsoft.com/windows-hardware/drivers/ddi/winsplp/nf-winsplp-writeport) function.

### `pfnReadPort`

Pointer to the print monitor's [ReadPort](https://learn.microsoft.com/windows-hardware/drivers/ddi/winsplp/nf-winsplp-readport) function.

### `pfnEndDocPort`

A print monitor's **EndDocPort** function performs the tasks required to end a print job on the specified port.

### `pfnClosePort`

Pointer to the print monitor's [ClosePort](https://learn.microsoft.com/windows-hardware/drivers/ddi/winsplp/nf-winsplp-closeport) function.

### `pfnAddPort`

> [!CAUTION]
> The [AddPort](https://learn.microsoft.com/previous-versions/ff545022(v=vs.85)) function is obsolete and should not be used.

[AddPort](https://learn.microsoft.com/previous-versions/ff545022(v=vs.85)) creates a port and adds it to the list of ports currently supported by the specified monitor in the spooler environment.

### `pfnAddPortEx`

(Obsolete. Must be **NULL**.) Pointer to the print monitor's [AddPortEx](https://learn.microsoft.com/previous-versions/ff545025(v=vs.85)) function. (Port monitors only.)

### `pfnConfigurePort`

> [!CAUTION]
> The [ConfigurePort](https://learn.microsoft.com/previous-versions/ff546286(v=vs.85)) function is obsolete and should not be used. Use [ConfigurePortUI](https://learn.microsoft.com/windows-hardware/drivers/ddi/winsplp/nf-winsplp-configureportui) instead.

[ConfigurePort](https://learn.microsoft.com/previous-versions/ff546286(v=vs.85)) is a port management function that configures the specified port.

### `pfnDeletePort`

> [!CAUTION]
> The **DeletePort** function is obsolete and and should not be used.

**DeletePort** deletes a port from the monitor's environment.

### `pfnGetPrinterDataFromPort`

A port monitor's **GetPrinterDataFromPort** function obtains status information from a bidirectional printer and returns it to the caller.

### `pfnSetPortTimeOuts`

A port monitor server DLL's `SetPortTimeOuts` function sets port time-out values for an open port.

### `pfnXcvOpenPort`

Pointer to the print monitor's [XcvOpenPort](https://learn.microsoft.com/windows-hardware/drivers/ddi/winsplp/nf-winsplp-xcvopenport) function. (Port monitors only.)

### `pfnXcvDataPort`

Pointer to the print monitor's [XcvDataPort](https://learn.microsoft.com/windows-hardware/drivers/ddi/winsplp/nf-winsplp-xcvdataport) function. (Port monitors only.)

### `pfnXcvClosePort`

Pointer to the print monitor's [XcvClosePort](https://learn.microsoft.com/windows-hardware/drivers/ddi/winsplp/nf-winsplp-xcvcloseport) function. (Port monitors only.)

## Remarks

The following sections describe each callback member in more detail.

### AddPort

```cpp
typedef BOOL (WINAPI *pfnAddPort)(
  _In_ HANDLE hMonitor,
  _In_ LPWSTR pName,
  _In_ HWND   hWnd,
  _In_ LPWSTR pMonitorName
);
```

#### Parameters (AddPort)

##### Monitor [in] (AddPort)

Caller supplied monitor instance handle. This is the handle returned by the monitor's InitializePrintMonitor2 function. (This parameter does not exist if the print monitor supports InitializePrintMonitor2 instead of InitializePrintMonitor2.)

##### pName [in] (AddPort)

Pointer to a null-terminated string that specifies the name of the server to which the port is connected. If pName is NULL, the port is local.

##### hWnd [in] (AddPort)

Handle to the parent window of the dialog box in which the port name will be entered.

##### pMonitorName [in] (AddPort)

Pointer to a null-terminated string that specifies the monitor associated with the port.

#### Return value (AddPort)

The return value is TRUE if the function is successful, and FALSE otherwise.

### ConfigurePort

```cpp
typedef BOOL (WINAPI *pfnConfigurePort)(
  _In_ HANDLE hMonitor,
  _In_ LPWSTR pName,
  _In_ HWND   hWnd,
  _In_ LPWSTR pPortName
);
```

#### Parameters (ConfigurePort)

##### hMonitor [in] (ConfigurePort)

Caller supplied monitor instance handle. This is the handle returned by the monitor's InitializePrintMonitor2 function. (This parameter does not exist if the print monitor supports InitializePrintMonitor instead of InitializePrintMonitor2.)

##### pName [in] (ConfigurePort)

Pointer to a null-terminated string that specifies the name of the server on which the given port exists. If this string is NULL, the port is local.

##### hWnd [in] (ConfigurePort)

Handle to the parent window of the dialog box in which the configuration information will be entered.

##### pPortName [in] (ConfigurePort)

Pointer to a null-terminated string that specifies the name of the port to be configured.

#### Return value (ConfigurePort)

The return value is TRUE if the function is successful.

### DeletePort

```cpp
pfnDeletePort DeletePort;

BOOL WINAPI DeletePort(
  _In_ HANDLE hMonitor,
  _In_ LPWSTR pName,
  _In_ HWND   hWnd,
  _In_ LPWSTR pPortName
)
```

#### Parameters (DeletePort)

##### hMonitor [in] (DeletePort)

Caller supplied monitor instance handle. This is the handle returned by the monitor's InitializePrintMonitor2 function. (This parameter does not exist if the print monitor supports InitializePrintMonitor instead of InitializePrintMonitor2.)

##### pName [in] (DeletePort)

Pointer to a null-terminated string that specifies the name of the server on which the port to be deleted exists. If this parameter is NULL, the port is local.

##### hWnd [in] (DeletePort)

Handle to the parent window of the port-deletion dialog box.

##### pPortName [in] (DeletePort)

Pointer to a null-terminated string that names the port to be deleted.

#### Return value (DeletePort)

The return value is TRUE if the function is successful.

### EndDocPort

```cpp
typedef BOOL ( WINAPI *pfnEndDocPort)(
  _In_ HANDLE hPort
);
```

#### Parameters (EndDocPort)

##### hPort [in] (EndDocPort)

Caller-supplied port handle.

#### Return value (EndDocPort)

If the operation succeeds, the function should return TRUE. Otherwise it should return FALSE.

### EnumPorts

```cpp
typedef BOOL (WINAPI *pfnEnumPorts)(
  _In_     HANDLE  hMonitor,
  _In_opt_ LPWSTR  pName,
  _In_     DWORD   Level,
  _Out_    LPBYTE  pPorts,
  _In_     DWORD   cbBuf,
  _Out_    LPDWORD pcbNeeded,
  _Out_    LPDWORD pcReturned
);
```

#### Parameters (EnumPorts)

##### hMonitor [in] (EnumPorts)

Caller supplied monitor instance handle. This is the handle returned by the monitor's InitializePrintMonitor2 function. (This parameter does not exist if the print monitor supports InitializePrintMonitor instead of InitializePrintMonitor2.)

##### pName [in, optional] (EnumPorts)

Caller-supplied pointer to a string containing the name of the server whose ports are to be enumerated. A NULL pointer represents the system on which the port monitor server DLL is executing.

##### Level [in] (EnumPorts)

Caller-supplied value indicating the type of structures to be returned in the buffer pointed to by pPorts.

Possible values are 1 (PORT_INFO_1) or 2 (PORT_INFO_2).

##### pPorts [out] (EnumPorts)

Caller-supplied pointer to a buffer to receive port information. Returned information must consist of an array of [PORT_INFO_1](https://learn.microsoft.com/windows/win32/printdocs/port-info-1) or [PORT_INFO_2](https://learn.microsoft.com/windows/win32/printdocs/port-info-2) structures, followed by the strings pointed to by structure members.

##### cbBuf [in] (EnumPorts)

Caller-supplied size, in bytes, of the buffer pointed to by pPorts.

##### pcbNeeded [out] (EnumPorts)

Caller-supplied pointer to a location to receive the buffer size, in bytes, required to contain all returned information.

##### pcReturned [out] (EnumPorts)

Caller-supplied pointer to a location to receive the number enumerated ports.

#### Return value (EnumPorts)

If the operation succeeds, the function should return TRUE. Otherwise it should return FALSE.

### GetPrinterDataFromPort

```cpp
pfnGetPrinterDataFromPort GetPrinterDataFromPort;

BOOL WINAPI GetPrinterDataFromPort(
  _In_  HANDLE  hPort,
  _In_  DWORD   ControlID,
  _In_  LPWSTR  pValueName,
  _In_  LPWSTR  lpInBuffer,
  _In_  DWORD   cbInBuffer,
  _Out_ LPWSTR  lpOutBuffer,
  _In_  DWORD   cbOutBuffer,
  _Out_ LPDWORD lpcbReturned
)
```

#### Parameters (GetPrinterDataFromPort)

##### hPort [in] (GetPrinterDataFromPort)

Caller-supplied port handle.

##### ControlID [in] (GetPrinterDataFromPort)

Caller-supplied device I/O control code. A value of zero indicates a value name is supplied by pValueName.

##### pValueName [in] (GetPrinterDataFromPort)

Caller-supplied pointer to a string identifying the information being requested. Valid only if ControlID is zero.

##### lpInBuffer [in] (GetPrinterDataFromPort)

Caller-supplied pointer to a buffer containing input data. Used only if ControlID is nonzero.

##### cbInBuffer [in] (GetPrinterDataFromPort)

Caller-supplied size, in bytes, of the buffer pointed to by lpInBuffer.

##### lpOutBuffer [out] (GetPrinterDataFromPort)

Caller-supplied pointer to a buffer to receive the requested data.

##### cbOutBuffer [in] (GetPrinterDataFromPort)

Caller-supplied size, in bytes, of the buffer pointed to by lpOutBuffer.

##### lpcbReturned [out] (GetPrinterDataFromPort)

Caller-supplied pointer to a location to receive the number of bytes written into the buffer pointed to by lpOutBuffer.

#### Return value (GetPrinterDataFromPort)

If the operation succeeds, the function should return TRUE. Otherwise it should return FALSE.

### OpenPortEx

```cpp
pfnOpenPortEx OpenPortEx;

BOOL WINAPI OpenPortEx(
  _In_  HANDLE           hMonitor,
  _In_  HANDLE           hMonitorPort,
  _In_  LPWSTR           pPortName,
  _In_  LPWSTR           pPrinterName,
  _Out_ PHANDLE          pHandle,
  _In_  struct _MONITOR2 *pMonitor
)
```

#### Parameters (OpenPortEx)

##### hMonitor [in] (OpenPortEx)

Caller supplied language monitor instance handle. This is the handle returned by the monitor's InitializePrintMonitor2 function. (This parameter does not exist if the print monitor supports InitializePrintMonitor instead of InitializePrintMonitor2.) In a cluster environment, there can be multiple instances of language monitors.

##### hMonitorPort [in] (OpenPortEx)

Caller supplied port monitor instance handle. This is the handle returned by the monitor's InitializePrintMonitor2 function. (This parameter does not exist if the print monitor supports InitializePrintMonitor instead of InitializePrintMonitor2.) A language monitor must use this handle when it calls functions in the port monitor's **MONITOR2** structure.

##### pPortName [in] (OpenPortEx)

Caller-supplied pointer to a string containing the name of the port to be opened.

##### pPrinterName [in] (OpenPortEx)

Caller-supplied pointer to a string containing the name of the printer that is connected to the port.

##### pHandle [out] (OpenPortEx)

Caller-supplied pointer to a location to receive a port handle.

##### pMonitor [in] (OpenPortEx)

Caller-supplied pointer to the **MONITOR2** structure returned by a port monitor's InitializePrintMonitor2 function.

#### Return value (OpenPortEx)

If the operation succeeds, the function should return TRUE. Otherwise it should return FALSE.

### SetPortTimeOuts

```cpp
BOOL (WINAPI *pfnSetPortTimeOuts)
    (
    _In_ HANDLE  hPort,
    _In_ LPCOMMTIMEOUTS lpCTO,
    _In_ DWORD   reserved    // must be set to 0
    );
```

#### Parameters (SetPortTimeOuts)

##### hPort [in] (SetPortTimeOuts)

Caller-supplied handle to the open port on which to set the time-out values.

##### lpCTO [in] (SetPortTimeOuts)

Caller-supplied pointer to a [COMMTIMEOUTS](https://learn.microsoft.com/windows/win32/api/winbase/ns-winbase-commtimeouts) structure.

##### reserved [in] (SetPortTimeOuts)

Reserved for future use. Must be set to zero.

#### Return value (SetPortTimeOuts)

If the operation succeeds, the function should return TRUE. Otherwise it should return FALSE.

### StartDocPort

```cpp
typedef BOOL (WINAPI *pfnStartDocPort)(
  _In_ HANDLE hPort,
  _In_ LPWSTR pPrinterName,
  _In_ DWORD  JobId,
  _In_ DWORD  Level,
  _In_ LPBYTE pDocInfo
);
```

#### Parameters (StartDocPort)

##### hPort [in] (StartDocPort)

Caller-supplied port handle.

##### pPrinterName [in] (StartDocPort)

Caller-supplied pointer to a string containing the printer name.

##### JobId [in] (StartDocPort)

Caller-supplied, spooler-assigned job identifier.

##### Level [in] (StartDocPort)

Caller-supplied value indicating the type of structure pointed to by pDocInfo.

Possible values are 1 (DOC_INFO_1) or 2 (DOC_INFO_2).

##### pDocInfo [in] (StartDocPort)

Caller-supplied pointer to a [DOC_INFO_1](https://learn.microsoft.com/windows/win32/printdocs/doc-info-1) or [DOC_INFO_2](https://learn.microsoft.com/windows/win32/printdocs/doc-info-2) structure.

#### Return value (StartDocPort)

If the operation succeeds, the function should return TRUE. Otherwise it should return FALSE.

### Notes

The spooler calls [AddPort](https://learn.microsoft.com/previous-versions/ff545022(v=vs.85)) when it receives an application request to add a port to its environment. The spooler forwards the call to the named port monitor on the named server.

[AddPort](https://learn.microsoft.com/previous-versions/ff545022(v=vs.85)) allows a port to be added interactively. A monitor should prompt a user to enter the port name in a dialog box on the window associated with *hWnd*. **AddPort** should validate the entered port name by calling the Win32 EnumPorts function to ensure that no duplicate port names are added to the spooler environment. A monitor should also verify that the port is one that it supports.

The spooler does not support remote [AddPort](https://learn.microsoft.com/previous-versions/ff545022(v=vs.85)) calls. Consequently, **AddPort** implementations can ignore the *pName* and *pMonitorName* parameters.

The spooler calls [ConfigurePort](https://learn.microsoft.com/previous-versions/ff546286(v=vs.85)) so a port monitor can perform port configuration. **ConfigurePort** can offer a dialog box to obtain some or all of the necessary port configuration information from the user.

The spooler does not support remote [ConfigurePort](https://learn.microsoft.com/previous-versions/ff546286(v=vs.85)) calls; consequently, monitors can ignore the *pName* parameter.

The spooler calls **DeletePort** so a port monitor can delete a port from the monitor's environment. The monitor should delete the specified port from its state. The spooler will not call **DeletePort** on a monitor as long as a port is open.

Applications can delete local and remote ports. The printer UI displays a confirmation message box before the spooler calls **DeletePort**, so a monitor should ignore the *hWnd* parameter and not display another dialog box.

[Language monitors](https://learn.microsoft.com/windows-hardware/drivers/print/language-monitors) and port monitor server DLLs are required to define an **EndDocPort** function and include the function's address in a [**MONITOR2**](https://learn.microsoft.com/windows-hardware/drivers/ddi/winsplp/ns-winsplp-_monitor2) structure.

The handle received as the function's hPort argument is the port handle that the monitor's [OpenPort](https://learn.microsoft.com/windows-hardware/drivers/ddi/winsplp/nf-winsplp-openport) or [OpenPortEx](https://learn.microsoft.com/previous-versions/ff559596(v=vs.85)) function supplied.

A language monitor's **EndDocPort** function typically calls the associated port monitor's **EndDocPort** function. It should also notify the spooler when the printing device has finished the job by calling [**SetJob**](https://learn.microsoft.com/windows/win32/printdocs/setjob), specifying a command of JOB_CONTROL_LAST_PAGE_EJECTED. Language monitors for bidirectional printers should not call **SetJob** until the printer has sent notification that the job is really finished.

A port monitor server DLL's **EndDocPort** function typically calls the [**CloseHandle**](https://learn.microsoft.com/windows/win32/api/handleapi/nf-handleapi-closehandle) function, to close the handle that was previously obtained by calling [CreateFile](https://learn.microsoft.com/windows/win32/api/fileapi/nf-fileapi-createfilea) from within [StartDocPort](https://learn.microsoft.com/previous-versions/ff562710(v=vs.85)). It should also notify the spooler when the printing device has finished the job, by calling **SetJob**, specifying a command of JOB_CONTROL_SENT_TO_PRINTER. (If a spooler is communicating with the port through a language monitor, it doesn't consider the job complete until the language monitor sends JOB_CONTROL_LAST_PAGE_EJECTED.)

The **EndDocPort** function should free all resources that were allocated by the **StartDocPort** function.

You might want to modify the **EndDocPort** function's behavior if the user has deleted or restarted the print job. The function can call [**GetJob**](https://learn.microsoft.com/windows/win32/printdocs/getjob), and check for a status of JOB_STATUS_DELETING or JOB_STATUS_RESTART, to see if either of these events has occurred.

Port monitor server DLLs are required to define an **EnumPorts** function and include the function's address in a [**MONITOR2**](https://learn.microsoft.com/windows-hardware/drivers/ddi/winsplp/ns-winsplp-_monitor2) structure. Language monitors do not export this function.

The purpose of the **EnumPorts** function is to enumerate the ports currently supported by a print monitor. These ports are ones that were previously specified to the monitor's [AddPortUI](https://learn.microsoft.com/windows-hardware/drivers/ddi/winsplp/nf-winsplp-addportui) or [AddPortEx](https://learn.microsoft.com/previous-versions/ff545025(v=vs.85)) function.

The **EnumPorts** function should fill the buffer pointed to by *pPort* with an array of PORT_INFO_1 or PORT_INFO_2 structures. Then starting in a memory location following the last array element, the function must load all the strings pointed to by the array's structure members. Refer to localmon.dll, a [sample port monitor](https://learn.microsoft.com/windows-hardware/drivers/print/sample-port-monitor), for an example of how to do this. The function must also return the number of structures supplied (that is, the number of supported ports) by placing the number in the location pointed to by *pcReturned*.

The caller specifies the size of the supplied buffer in *cbBuf*. If the buffer is too small, the function should place the required buffer size in the location pointed to by *pcbNeeded*, call [**SetLastError**](https://learn.microsoft.com/windows/win32/api/errhandlingapi/nf-errhandlingapi-setlasterror) specifying ERROR_INSUFFICIENT_BUFFER, and return **FALSE**.

If *Level* contains an invalid level number, the function should call **SetLastError** specifying ERROR_INVALID_LEVEL, and return **FALSE**. Some port monitors only support a level value of 1.

The port monitor must support localization of strings pointed to by the **pMonitorName** and **pDescription** members of the PORT_INFO_2 structure. These strings should be defined in resource files and obtained by calling [**LoadString**](https://learn.microsoft.com/windows/win32/api/winuser/nf-winuser-loadstringa).

The **fPortType** member of the PORT_INFO_2 structure is not used with NT-based operating systems.

[Language monitors](https://learn.microsoft.com/windows-hardware/drivers/print/language-monitors) and port monitor server DLLs can optionally define a **GetPrinterDataFromPort** function and include the function's address in a [**MONITOR2**](https://learn.microsoft.com/windows-hardware/drivers/ddi/winsplp/ns-winsplp-_monitor2) structure.

The function is meant for use with bidirectional printers, and can be used in the following two ways:

- As a means for requesting a language monitor to poll the printer port, to obtain the current value of printer-specific information that is stored in the registry.

- As a means for requesting a port monitor to send an I/O control code to the port driver.

If a language monitor's **GetPrinterDataFromPort** function receives a string pointer in *pValueName*, it should return a value in the supplied output buffer. Typically, the string represents a registry value name, and the spooler calls **GetPrinterDataFromPort** when an application calls the [**GetPrinterData**](https://learn.microsoft.com/windows/win32/printdocs/getprinterdata) function.

The language monitor's responsibility is to send a command to the printer hardware by calling the port monitor's [WritePort](https://learn.microsoft.com/windows-hardware/drivers/ddi/winsplp/nf-winsplp-writeport) function, and reading the response by calling [ReadPort](https://learn.microsoft.com/windows-hardware/drivers/ddi/winsplp/nf-winsplp-readport), to obtain the needed value. For example, pjlmon.dll, the [sample language monitor](https://learn.microsoft.com/windows-hardware/drivers/print/sample-language-monitor), can return values for a port's "Installed Memory" and "Available Memory" registry value names.

After the spooler calls **GetPrinterDataFromPort** to obtain a registry value, it updates the registry with the new value.

Typically, port monitors do not support calls to **GetPrinterDataFromPort** that include a string pointer in *pValueName*.

If a language monitor's **GetPrinterDataFromPort** function receives a nonzero I/O control code in *ControlID*, it should just call the associated port monitor's **GetPrinterDataFromPort** function and return the result. The *Kernel-Mode Drivers Reference* lists I/O control codes for parallel and serial ports.

When a port monitor's **GetPrinterDataFromPort** function receives a nonzero I/O control code in *ControlID*, it should call [**DeviceIOControl**](https://learn.microsoft.com/windows/win32/api/ioapiset/nf-ioapiset-deviceiocontrol) to pass the control code to the kernel-mode port driver. The *lpInBuffer*, *cbInBuffer*, *lpOutBuffer*, *cbOutBuffer*, and *lpcbReturned* parameter values should also be passed to **DeviceIOControl**.

Language monitors are required to define an `OpenPortEx` function and include its address in a [**MONITOR2**](https://learn.microsoft.com/windows-hardware/drivers/ddi/winsplp/ns-winsplp-_monitor2) structure. The `OpenPortEx` function is called by the print spooler when a print queue is being connected to a port.

The `OpenPortEx` function's primary purpose is to return a port handle that the caller can use as an input argument for subsequent calls to the language monitor's [StartDocPort](https://learn.microsoft.com/previous-versions/ff562710(v=vs.85)), [WritePort](https://learn.microsoft.com/windows-hardware/drivers/ddi/winsplp/nf-winsplp-writeport), [ReadPort](https://learn.microsoft.com/windows-hardware/drivers/ddi/winsplp/nf-winsplp-readport), [EndDocPort](https://learn.microsoft.com/previous-versions/ff548742(v=vs.85)), and [GetPrinterDataFromPort](https://learn.microsoft.com/previous-versions/ff550506(v=vs.85)) functions. Because a language monitor typically implements these functions by calling the equivalent functions in its associated port monitor, a language monitor typically obtains a port handle by calling the port monitor's [OpenPort](https://learn.microsoft.com/windows-hardware/drivers/ddi/winsplp/nf-winsplp-openport) function. For more information see [Language and Port Monitor Interaction](https://learn.microsoft.com/windows-hardware/drivers/print/language-and-port-monitor-interaction).

The `OpenPortEx` function's *pMonitor* parameter is a pointer to the port monitor's [**MONITOR2**](https://learn.microsoft.com/windows-hardware/drivers/ddi/winsplp/ns-winsplp-_monitor2) structure. This structure contains pointers to the port monitor's callable functions. The `OpenPortEx` function should check the structure to verify that all required function pointers are non-**NULL**. If the structure is valid, the function should copy it into local storage. Otherwise `OpenPortEx` should call **SetLastError**, specifying ERROR_INVALID_PRINT_MONITOR, and return **FALSE**.

Print monitor functions that accept a port handle as input do not also accept a monitor handle. Therefore, the `OpenPortEx` function must store the received monitor handle in a location that can be referenced by the port handle. This allows the functions that accept a port handle to reference the monitor handle.

A port monitor server DLL's `SetPortTimeOuts` function allows a language monitor to specify port time-out values for an open port. The function is optional, and must be provided only if the port monitor controls a port that allows the modification of port time-out values. If the function is defined, its address must be included in a [**MONITOR2**](https://learn.microsoft.com/windows-hardware/drivers/ddi/winsplp/ns-winsplp-_monitor2) structure.

The function is called by pjlmon.dll, the [sample language monitor](https://learn.microsoft.com/windows-hardware/drivers/print/sample-language-monitor), and you can write a customized language monitor that calls it. The print spooler does not call `SetPortTimeOuts`.

The port monitor should initialize the port's time-out values from within its [OpenPort](https://learn.microsoft.com/windows-hardware/drivers/ddi/winsplp/nf-winsplp-openport) function.

[Language monitors](https://learn.microsoft.com/windows-hardware/drivers/print/language-monitors) and port monitor server DLLs are required to define a `StartDocPort` function and include the function's address in a [**MONITOR2**](https://learn.microsoft.com/windows-hardware/drivers/ddi/winsplp/ns-winsplp-_monitor2) structure.

The handle received as the function's *hPort* argument is the port handle that the monitor's [OpenPort](https://learn.microsoft.com/windows-hardware/drivers/ddi/winsplp/nf-winsplp-openport) or [OpenPortEx](https://learn.microsoft.com/previous-versions/ff559596(v=vs.85)) function supplied.

A language monitor's `StartDocPort` function typically calls the associated port monitor's `StartDocPort` function.

A port monitor server DLL's `StartDocPort` function typically calls the [CreateFile](https://learn.microsoft.com/windows/win32/api/fileapi/nf-fileapi-createfilea) function, to create a connection to the kernel-mode port driver.

If necessary, the port monitor should prevent other processes from using the specified port until [EndDocPort](https://learn.microsoft.com/previous-versions/ff548742(v=vs.85)) is called. For example, a port monitor for a COM port must ensure that, while a spooler is sending printer data to the port, another application does not assume the port is connected to a particular communications device and then attempt to communicate with that device. This cautionary note does not apply to the local print provider, which guarantees that it never calls `StartDocPort` twice in succession without an intervening call to **EndDocPort**, but it does apply to print providers that do not make this guarantee.

## See also

[**MONITOR2**](https://learn.microsoft.com/windows-hardware/drivers/ddi/winsplp/ns-winsplp-_monitor2)

[MONITORUI](https://learn.microsoft.com/windows-hardware/drivers/ddi/winsplp/ns-winsplp-_monitorui)