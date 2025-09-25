# PFAX_LINECALLBACK callback function

## Description

The *FaxLineCallback* function is an application-defined or library-defined callback function that the fax service calls to deliver Telephony Application Programming Interface (TAPI) events to the fax service provider (FSP).

The **PFAX_LINECALLBACK** data type is a pointer to a *FaxLineCallback* function. *FaxLineCallback* is a placeholder for an application-defined or library-defined function name.

## Parameters

### `FaxHandle` [in]

Type: **HANDLE**

Specifies a fax handle returned by the [FaxDevStartJob](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxdev/nf-faxdev-faxdevstartjob) function.

### `hDevice` [in]

Type: **DWORD**

Specifies a handle to either a line device or a call device. To determine whether this handle is a line handle or a call handle, use the context that the *dwMessage* parameter provides.

### `dwMessage` [in]

Type: **DWORD**

Specifies a line device or a call device message.

### `dwInstance`

Type: **DWORD_PTR**

Reserved; should not be used by the FSP.

### `dwParam1` [in]

Type: **DWORD_PTR**

Specifies a parameter for the message. For information about parameter values passed in this structure, see [Line Device Messages](https://learn.microsoft.com/windows/desktop/Tapi/line-device-messages) in the TAPI documentation.

### `dwParam2` [in]

Type: **DWORD_PTR**

Specifies a parameter for the message.

### `dwParam3` [in]

Type: **DWORD_PTR**

Specifies a parameter for the message.

## Remarks

The FSP must register the *FaxLineCallback* callback function by passing its address when the fax service calls the [FaxDevInitialize](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxdev/nf-faxdev-faxdevinitialize) function.

## See also

[Fax Service Provider Functions](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-fax-service-provider-functions)

[FaxDevInitialize](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxdev/nf-faxdev-faxdevinitialize)

[FaxDevStartJob](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxdev/nf-faxdev-faxdevstartjob)

[Using the Fax Service Provider API](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-using-the-fax-service-provider-api)

[lineInitializeEx](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-lineinitializeexa)