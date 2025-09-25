# DPA_SaveStream function

## Description

[**DPA_SaveStream** is available in Windows Vista. It might be altered or unavailable in subsequent versions. ]

Saves the dynamic pointer array (DPA) to a stream by writing out a header, and then calling the specified callback function to write each element.

## Parameters

### `hdpa` [in]

Type: **HDPA**

Receives a handle to a DPA.

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
| **S_OK** | Indicates that the callback function was unsuccessful in saving the element; however, the process should continue. |
| **S_FALSE** | Indicates that even though the callback was unsuccessful, the process was uninterrupted. |
| **E_INVALIDARG** | Indicates that one or more of the parameters is invalid. |

## Remarks

This function must be called directly from ComCtl32.dll. It is ordinal 10.

The callback is responsible for writing the *pvInstData* data to the stream.