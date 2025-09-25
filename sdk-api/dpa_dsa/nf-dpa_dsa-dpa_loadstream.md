# DPA_LoadStream function

## Description

[**DPA_LoadStream** is available in Windows Vista. It might be altered or unavailable in subsequent versions. ]

Loads the dynamic pointer array (DPA) from a stream by calling the specified callback function to read each element.

## Parameters

### `phdpa` [out]

Type: **HDPA***

A handle to a DPA.

### `pfn` [in]

Type: **[PFNDPASTREAM](https://learn.microsoft.com/windows/desktop/api/dpa_dsa/nc-dpa_dsa-pfndpastream)**

The callback function. See [PFNDPASTREAM](https://learn.microsoft.com/windows/desktop/api/dpa_dsa/nc-dpa_dsa-pfndpastream) for the callback function prototype.

### `pstream` [in]

Type: **[IStream](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-istream)***

An [IStream](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-istream) object.

### `pvInstData` [in]

Type: **void***

A pointer to callback data. *pvInstData* is passed as a parameter to *pfn*.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Returns one of the following values.

| Return code | Description |
| --- | --- |
| **S_OK** | Indicates that the callback function was successful and the element was loaded. |
| **S_FALSE** | Indicates that the callback function was unsuccessful in loading the element; however, the process should continue. |
| **E_INVALIDARG** | Indicates that one or more of the parameters is invalid. |
| **E_FAIL** | Indicates that the stream object could not be read. |
| **E_OUTOFMEMORY** | The buffer length is invalid or there was insufficient memory to complete the operation. |

## Remarks

This function must be called directly from ComCtl32.dll. It is ordinal 9.

The callback is responsible for writing the *pvInstData* data to the stream.