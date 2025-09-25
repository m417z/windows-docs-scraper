## Description

A port monitor server DLL's **XcvDataPort** function receives information from, and returns information to, the port monitor's UI DLL.

## Parameters

### `hXcv` [in]

Caller-supplied printer handle, obtained by calling **OpenPrinter** (described in the Microsoft Windows SDK documentation). This handle is created and returned by the [XcvOpenPort](https://learn.microsoft.com/windows-hardware/drivers/ddi/winsplp/nf-winsplp-xcvopenport) function.

### `pszDataName` [in]

Caller-supplied pointer to a string representing the name of the data being requested. For more information, see the following Remarks section.

### `pInputData` [in]

Caller-supplied pointer to a buffer containing input data.

### `cbInputData`

Caller-supplied size, in bytes, of the buffer pointed to by *pInputData*.

### `pOutputData` [out]

Caller-supplied pointer to a buffer to receive output data.

### `cbOutputData`

Caller-supplied size, in bytes, of the buffer pointed to by *pOutputData*.

### `pcbOutputNeeded` [out]

Caller-supplied pointer to a location to receive the minimum size, in bytes, required for the buffer pointed to by *pOutputData*.

## Return value

If the operation succeeds, this function should return ERROR_SUCCESS. Otherwise, it should return an ERROR_-prefixed Win32 error code. The print monitor UI DLL receives this value in the *pdwStatus* location specified for [XcvData](https://learn.microsoft.com/previous-versions/ff564255(v=vs.85)).

## Syntax

```cpp
DWORD XcvDataPort(
  _In_  HANDLE  hXcv,
  _In_  LPCWSTR pszDataName,
  _In_  PBYTE   pInputData,
        DWORD   cbInputData,
  _Out_ PBYTE   pOutputData,
        DWORD   cbOutputData,
  _Out_ PDWORD  pcbOutputNeeded
);
```

## Remarks

Port monitor server DLLs are required to define an **XcvDataPort** function so they can receive information from, and return information to, a port monitor UI DLL. The function's address must be included in a [**MONITOR2**](https://learn.microsoft.com/windows-hardware/drivers/ddi/winsplp/ns-winsplp-_monitor2) structure.

The **XcvDataPort** function is called by the spooler's [XcvData](https://learn.microsoft.com/previous-versions/ff564255(v=vs.85)) function. The function parameters for **XcvDataPort** and **XcvData** are almost identical. (**XcvData** has an additional parameter, *pdwStatus*, that is not present in **XcvDataPort**.)

The string pointed to by *pszDataName* specifies the operation to be performed. The function must recognize the following data name strings:

| Data Name String | Operation |
|---|---|
| L"AddPort" | All information needed for adding a port has been sent. The function should perform operations necessary to add the specified port, including writing the port name in the registry under the Ports key. The *pInputData* parameter points to a NULL-terminated port name string. If the function returns ERROR_SUCCESS, the spooler marks the port as added. This string is specified by the print monitor UI DLL, from within its [AddPortUI](https://learn.microsoft.com/windows-hardware/drivers/ddi/winsplp/nf-winsplp-addportui) function. |
| L"DeletePort" | All information needed for deleting a port has been sent. The function should perform operations necessary to delete the specified port, including removing the port name from the registry's Ports key. The *pInputData* parameter points to a NULL-terminated port name string. If the function returns ERROR_SUCCESS, the spooler marks the port as deleted. This string is specified by the print monitor UI DLL, from within its [DeletePortUI](https://learn.microsoft.com/windows-hardware/drivers/ddi/winsplp/nf-winsplp-deleteportui) function. |
| L"MonitorUI" | The function should use *pOutputData* to return the name of the associated port monitor UI DLL. This string is specified by the print spooler, when an application calls the Microsoft Windows SDK **AddPort** function. |

Typically, the function is written to recognize additional, customized strings that are sent by the UI DLL from within its [AddPortUI](https://learn.microsoft.com/windows-hardware/drivers/ddi/winsplp/nf-winsplp-addportui), [ConfigurePortUI](https://learn.microsoft.com/windows-hardware/drivers/ddi/winsplp/nf-winsplp-configureportui), and [DeletePortUI](https://learn.microsoft.com/windows-hardware/drivers/ddi/winsplp/nf-winsplp-deleteportui) functions. These strings might represent commands that request current configuration values from the server DLL, or that deliver new values. For example, your **XcvDataPort** function might recognize the string "GetTransmissionRetryTimeout", which your UI DLL could send to your server DLL to request the currently stored transmission retry time-out value. Or, you might define a set of strings that must be sent before "AddPort" or "DeletePort" is sent, where the strings are used to supply information identifying the port to add or delete.

For a given *pszDataName* string and input buffer, **XcvDataPort** might first be called with a *cbOutputData* value of zero. The function should return a required buffer size in *pcbOutputNeeded*, along with a return value of ERROR_INSUFFICIENT_BUFFER. The caller can use the value received in *pcbOutputNeeded* to allocate an output buffer of adequate size, and can then call **XcvDataPort** again, this time specifying the allocated buffer size in *cbOutputData*.

The **XcvDataPort** function must validate all input arguments. Specifically, the function must:

- Validate the contents of the string pointed to by the *pszDataName* parameter. If this string represents an administrative operation (typically adding, deleting, or configuring a port), the **XcvDataPort** function should compare the granted access mask that was previously received by the [XcvOpenPort](https://learn.microsoft.com/windows-hardware/drivers/ddi/winsplp/nf-winsplp-xcvopenport) function with SERVER_ACCESS_ADMINISTER. If the comparison fails, **XcvDataPort** must return ERROR_ACCESS_DENIED.

- Validate the contents of the buffer pointed to by the *pInputData* parameter. When the spooler calls the **XcvOpenPort** function, it performs no validation on the contents of this buffer. The monitor can make no assumptions about the validity of this data, which can come from a malicious application.

If you are writing a port monitor that will communicate with TCPMON, see [TCPMON Xcv Interface](https://learn.microsoft.com/windows-hardware/drivers/print/tcpmon-xcv-interface).

## See also

[XcvOpenPort](https://learn.microsoft.com/windows-hardware/drivers/ddi/winsplp/nf-winsplp-xcvopenport)

[DeletePortUI](https://learn.microsoft.com/windows-hardware/drivers/ddi/winsplp/nf-winsplp-deleteportui)

[ConfigurePortUI](https://learn.microsoft.com/windows-hardware/drivers/ddi/winsplp/nf-winsplp-configureportui)

[AddPortUI](https://learn.microsoft.com/windows-hardware/drivers/ddi/winsplp/nf-winsplp-addportui)

[XcvData](https://learn.microsoft.com/previous-versions/ff564255(v=vs.85))