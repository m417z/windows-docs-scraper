# ID3D10Device::CheckCounter

## Description

Get the type, name, units of measure, and a description of an existing counter.

## Parameters

### `pDesc` [in]

Type: **const [D3D10_COUNTER_DESC](https://learn.microsoft.com/windows/desktop/api/d3d10/ns-d3d10-d3d10_counter_desc)***

Pointer to a counter description (see [D3D10_COUNTER_DESC](https://learn.microsoft.com/windows/desktop/api/d3d10/ns-d3d10-d3d10_counter_desc)). Specifies which counter information is to be retrieved about.

### `pType` [out]

Type: **[D3D10_COUNTER_TYPE](https://learn.microsoft.com/windows/desktop/api/d3d10/ne-d3d10-d3d10_counter_type)***

Pointer to the data type of a counter (see [D3D10_COUNTER_TYPE](https://learn.microsoft.com/windows/desktop/api/d3d10/ne-d3d10-d3d10_counter_type)). Specifies the data type of the counter being retrieved.

### `pActiveCounters` [out]

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)***

Pointer to the number of hardware counters that are needed for this counter type to be created. All instances of the same counter type use the same hardware counters.

### `szName` [out]

Type: **[LPSTR](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

String to be filled with a brief name for the counter. May be **NULL** if the application is not interested in the name of the counter.

### `pNameLength` [in, out]

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)***

Length of the string returned to szName. Can be **NULL**.

### `szUnits` [out]

Type: **[LPSTR](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Name of the units a counter measures, provided the memory the pointer points to has enough room to hold the string. Can be **NULL**. The returned string will always be in English.

### `pUnitsLength` [in, out]

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)***

Length of the string returned to szUnits. Can be **NULL**.

### `szDescription` [out]

Type: **[LPSTR](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A description of the counter, provided the memory the pointer points to has enough room to hold the string. Can be **NULL**. The returned string will always be in English.

### `pDescriptionLength` [in, out]

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)***

Length of the string returned to szDescription. Can be **NULL**.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

This method returns one of the following [Direct3D 10 Return Codes](https://learn.microsoft.com/windows/desktop/direct3d10/d3d10-graphics-reference-returnvalues).

## Remarks

Length parameters can be **NULL**, which indicates the application is not interested in the length nor the corresponding string value. When a length parameter is non-**NULL** and the corresponding string is **NULL**, the input value of the length parameter is ignored, and the length of the corresponding string (including terminating **NULL**) will be returned through the length parameter. When length and the corresponding parameter are both non-**NULL**, the input value of length is checked to ensure there is enough room, and then the length of the string (including terminating **NULL** character) is passed out through the length parameter.

## See also

[ID3D10Device Interface](https://learn.microsoft.com/windows/desktop/api/d3d10/nn-d3d10-id3d10device)