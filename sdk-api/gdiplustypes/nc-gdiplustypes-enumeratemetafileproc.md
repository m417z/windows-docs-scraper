## Description

**EnumerateMetafileProc** is the signature of a callback function that you implement in your application for the [**Graphics::EnumerateMetafile**](https://learn.microsoft.com/windows/win32/api/gdiplusgraphics/nf-gdiplusgraphics-graphics-enumeratemetafile(constmetafile_constpointf_int_constrectf__unit_enumeratemetafileproc_void_constimageattributes)) method (and overloads).

In turn, your implementation can call [**Metafile::PlayRecord**](https://learn.microsoft.com/windows/win32/api/gdiplusheaders/nf-gdiplusheaders-metafile-playrecord) to play the record that was just enumerated.

## Parameters

### `unnamedParam1`

Type: **[EmfPlusRecordType](https://learn.microsoft.com/windows/win32/api/gdiplusenums/ne-gdiplusenums-emfplusrecordtype)**

The WMF, EMF, or EMF+ record type.

### `unnamedParam2`

Type: **[UINT](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

Flags; always 0 for WMF/EMF records.

### `unnamedParam3`

Type: **[UINT](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

The size of the record data (in bytes), or 0 if no data.

### `unnamedParam4`

Type: **[BYTE](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)***

A pointer to the record data, or **NULL** if no data.

### `unnamedParam5`

Type: **[VOID](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)\***

A pointer to callbackData, if any.

## Return value

Return **FALSE** to abort the enumeration process; return **TRUE** to continue it.

## Remarks

## See also