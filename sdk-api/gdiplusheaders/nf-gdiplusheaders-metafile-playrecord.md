# Metafile::PlayRecord

## Description

The **Metafile::PlayRecord** method plays a metafile record.

## Parameters

### `recordType` [in]

Type: **[EmfPlusRecordType](https://learn.microsoft.com/windows/desktop/api/gdiplusenums/ne-gdiplusenums-emfplusrecordtype)**

Element of the [EmfPlusRecordType](https://learn.microsoft.com/windows/desktop/api/gdiplusenums/ne-gdiplusenums-emfplusrecordtype) enumeration that specifies the type of metafile record to be played.

### `flags` [in]

Type: **UINT**

Set of flags that specify attributes of the record to be played.

### `dataSize` [in]

Type: **UINT**

Integer that specifies the number of bytes contained in the record data.

### `data` [in]

Type: **const BYTE***

Pointer to an array of bytes that contains the record data.

## Return value

Type: **[Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status)**

If the method succeeds, it returns Ok, which is an element of the [Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status) enumeration.

If the method fails, it returns one of the other elements of the [Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status) enumeration.

## Remarks

This method is used in conjunction with the [EnumerateMetafile Methods](https://learn.microsoft.com/windows/desktop/api/gdiplusgraphics/nf-gdiplusgraphics-graphics-enumeratemetafile(inconstmetafile_inconstpointf_inint_inconstrectf__inunit_inenumeratemetafileproc_invoid_inconstimageattributes)) method of the [Graphics](https://learn.microsoft.com/windows/desktop/api/gdiplusgraphics/nl-gdiplusgraphics-graphics) class. The EnumerateMetafile Methods method calls an application-defined callback function for each record in a specified metafile. The callback function can display each record (or selected records) by calling the **Metafile::PlayRecord** method.

## See also

[EmfPlusRecordType](https://learn.microsoft.com/windows/desktop/api/gdiplusenums/ne-gdiplusenums-emfplusrecordtype)

[EnumerateMetafile Methods](https://learn.microsoft.com/windows/desktop/api/gdiplusgraphics/nf-gdiplusgraphics-graphics-enumeratemetafile(inconstmetafile_inconstpointf_inint_inconstrectf__inunit_inenumeratemetafileproc_invoid_inconstimageattributes))

[Loading and Displaying Metafiles](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-loading-and-displaying-metafiles-use)

[Metafile](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nl-gdiplusheaders-metafile)

[Metafiles](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-metafiles-about)