# Metafile::EmfToWmfBits

## Description

Converts an enhanced-format metafile to a Windows Metafile Format (WMF) metafile and stores the converted records in a specified buffer.

## Parameters

### `hemf` [in]

Type: **HENHMETAFILE**

Handle to the enhanced-format metafile that is to be converted.

### `cbData16` [in]

Type: **UINT**

Unsigned integer that specifies the number of bytes in the buffer pointed to by the *pData16* parameter.

### `pData16` [out]

Type: **LPBYTE**

Pointer to a buffer that receives the converted records. If *pData16* is **NULL**, **Metafile::EmfToWmfBits** returns the number of bytes required to store the converted metafile records.

### `iMapMode` [in, optional]

Type: **INT**

Optional. Specifies the mapping mode to use in the converted metafile. For a list of possible mapping modes, see [SetMapMode](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-setmapmode). The default value is MM_ANISOTROPIC.

### `eFlags` [in, optional]

Type: **[EmfToWmfBitsFlags](https://learn.microsoft.com/windows/desktop/api/gdiplusenums/ne-gdiplusenums-emftowmfbitsflags)**

Optional. Element of the [EmfToWmfBitsFlags](https://learn.microsoft.com/windows/desktop/api/gdiplusenums/ne-gdiplusenums-emftowmfbitsflags) enumeration that specifies options for the conversion. The default value is [EmfToWmfBitsFlagsDefault](https://learn.microsoft.com/windows/desktop/api/gdiplusenums/ne-gdiplusenums-emftowmfbitsflags).

## Return value

Type: **UINT**

If the method succeeds and the buffer pointer is **NULL**, the return value is the number of bytes required to store the converted records. If the method succeeds and the buffer pointer is a valid pointer, the return value is the size of the metafile data in bytes. If the method fails, the return value is zero.

## Remarks

When you call **Metafile::EmfToWmfBits** to determine the size of the required buffer, you must pass the same value for *eFlags* that you pass later when you call **Metafile::EmfToWmfBits** to perform the conversion. Otherwise, the size returned by the first call to **Metafile::EmfToWmfBits** will be incorrect.

This method cannot convert metafiles of type [EmfTypeEmfPlusOnly](https://learn.microsoft.com/windows/desktop/api/gdiplusenums/ne-gdiplusenums-emftowmfbitsflags). If you use this method to convert a metafile of type [EmfTypeEmfPlusDual](https://learn.microsoft.com/windows/desktop/api/gdiplusenums/ne-gdiplusenums-emftowmfbitsflags), the Enhanced Metafile (EMF) records in that metafile are converted, but the EMF+ records are not converted.

This method converts an enhanced metafile into a WMF metafile so that its picture can be displayed in an application that recognizes the older format.

The **Metafile::EmfToWmfBits** method does not invalidate the enhanced metafile handle. Call the [DeleteEnhMetaFile](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-deleteenhmetafile) function to release the handle when it is no longer needed.

To create a scalable WMF metafile, specify MM_ANISOTROPIC as the *iMapMode* parameter.

#### Examples

The following example converts an enhanced-format metafile to a WMF metafile. The last parameter passed to **Metafile::EmfToWmfBits** specifies that the enhanced-format metafile is embedded as a comment in the converted metafile.

```cpp
// Construct a Metafile object from an existing EMF disk file.
Metafile myMetafile(L"SourceMetafile.emf");

// Get a handle to the EMF metafile.
HENHMETAFILE hEmf = myMetafile.GetHENHMETAFILE();

// Determine the size of the buffer that will receive the converted records.
UINT size = Metafile::EmfToWmfBits(
   hEmf,
   0,
   NULL,
   MM_ANISOTROPIC,
   EmfToWmfBitsFlagsEmbedEmf);

// Allocate a buffer to receive the converted records.
BYTE* buffer = new BYTE[size];

// Convert the EMF records to WMF records.
INT convertedSize = Metafile::EmfToWmfBits(
   hEmf,
   size,
   buffer,
   MM_ANISOTROPIC,
   EmfToWmfBitsFlagsEmbedEmf);

// Get a handle to the converted metafile.
HMETAFILE hmf = SetMetaFileBitsEx(size, buffer);

// Write the WMF metafile to a disk file.
CopyMetaFile(hmf, TEXT("ConvertedMetafile.wmf"));

DeleteMetaFile(hmf);
DeleteEnhMetaFile(hEmf);
delete[] buffer;
```

## See also

[EmfType](https://learn.microsoft.com/windows/desktop/api/gdiplusenums/ne-gdiplusenums-emftype)

[GetWinMetaFileBits](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-getwinmetafilebits)

[Metafile](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nl-gdiplusheaders-metafile)

[Metafiles](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-metafiles-about)