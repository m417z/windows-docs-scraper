# SLGetGenuineInformationEx function

## Description

Specifies information about the genuine status of a Windows computer.

## Parameters

### `pAppId` [in]

Type: **const SLID***

A pointer to the application ID.

### `pwszValueName` [in]

Type: **PCWSTR**

The name associated with the value of the property to set.

### `peDataType` [out, optional]

Type: **[SLDATATYPE](https://learn.microsoft.com/windows/desktop/api/slpublic/ne-slpublic-sldatatype)***

A pointer to a value of the [SLDATATYPE](https://learn.microsoft.com/windows/desktop/api/slpublic/ne-slpublic-sldatatype) enumeration that specifies the data type in the *ppbValue* buffer.

### `pcbValue` [out]

Type: **UINT***

A pointer to the size, in bytes, of the *ppbValue* buffer.

### `ppbValue` [out]

Type: **BYTE****

A pointer to the genuine status retrieved. When finished using the memory, free it by calling the [LocalFree](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-localfree) function.

## Return value

Type: **HRESULT WINAPI**

If this function succeeds, it return **S_OK**. Otherwise, it returns an **HRESULT** error code.

| Return code/value | Description |
| --- | --- |
| **SL_E_NOT_SUPPORTED**<br><br>0xC004F016 | The name of value is not supported. |
| **SL_E_VALUE_NOT_FOUND**<br><br>0xC004F012 | The value for the input key was not found. |
| **SL_E_NOT_GENUINE**<br><br>0xC004F200 | The application licensing state is non-genuine. |