# FaxExtInitializeConfig function

## Description

The fax service calls the **FaxExtInitializeConfig** function to initialize the fax extension DLL. The service calls this function before it calls any other fax extension initialization function.

## Parameters

### `unnamedParam1` [in]

Type: **PFAX_EXT_GET_DATA**

Pointer to a [FaxExtGetData](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxext/nf-faxext-faxextgetdata) fax service callback function.

### `unnamedParam2` [in]

Type: **PFAX_EXT_SET_DATA**

Pointer to a [FaxExtSetData](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxext/nf-faxext-faxextsetdata) fax service callback function.

### `unnamedParam3` [in]

Type: **PFAX_EXT_REGISTER_FOR_EVENTS**

Pointer to a [FaxExtRegisterForEvents](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxext/nf-faxext-faxextregisterforevents) fax service callback function.

### `unnamedParam4` [in]

Type: **PFAX_EXT_UNREGISTER_FOR_EVENTS**

Pointer to a [FaxExtUnregisterForEvents](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxext/nf-faxext-faxextunregisterforevents) fax service callback function.

### `unnamedParam5` [in]

Type: **PFAX_EXT_FREE_BUFFER**

Pointer to a [FaxExtFreeBuffer](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxext/nf-faxext-faxextfreebuffer) fax service callback function.

## Return value

Type: **HRESULT**

If the function succeeds, the return value is **NOERROR**.

If the fax extension DLL returns a value other than **NOERROR**, the fax service considers the extension to be in an error state. Even if other extension initialization functions succeed, the fax service does not recognize the extension.

## Remarks

A fax extension DLL must export **FaxExtInitializeConfig** if it plans to implement the fax extension configuration mechanism and receive notifications from the fax service about changes in device configuration data.

The **FaxExtInitializeConfig** function exposes pointers to the callback functions that the fax service supplies. The fax extension DLL must store these pointers in a global variable for later use.

## See also

[FaxExtFreeBuffer](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxext/nf-faxext-faxextfreebuffer)

[FaxExtGetData](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxext/nf-faxext-faxextgetdata)

[FaxExtRegisterForEvents](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxext/nf-faxext-faxextregisterforevents)

[FaxExtSetData](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxext/nf-faxext-faxextsetdata)

[FaxExtUnregisterForEvents](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxext/nf-faxext-faxextunregisterforevents)