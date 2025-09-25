# SHGetInverseCMAP function

## Description

[This function is available through Windows XP and Windows Server 2003. It might be altered or unavailable in subsequent versions of Windows.]

Retrieves the inverse color table mapping for the halftone palette.

## Parameters

### `pbMap` [out]

Type: **BYTE***

A pointer to an array of **BYTE****s** that receives the inverse color table mapping, or a pointer to an **LPBYTE** which receives a pointer to a cached copy of the inverse color table mapping, depending on the value of the *cbMap* parameter.

### `cbMap` [in]

Type: **ULONG**

The size of the buffer pointed to by *pbMap*, which also defines its contents. Two values are recognized.

#### (sizeof(BYTE*))

The buffer pointed to by *pbMap* receives a pointer to a cached copy of the inverse color map table.

#### (32768)

The buffer pointed to by *pbMap* receives a copy of the inverse color map table. The buffer must be exactly 32,768 bytes in size.

## Return value

Type: **HRESULT**

If this function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

The inverse color mapping table is a table of 32,768 bytes. It contains the indexes of colors in the halftone palette. Each index is stored at a position in the buffer that corresponds to a particular RGB value expressed in 555 format. These pairings allow you to find a color in the halftone palette which is a close approximation of the original color.

For example, the method for determining a color in the halftone palette that is a close approximation for the color #306040 is as follows:

1. Decompose the color into its red, green, and blue components. In this case, the red component is 0x30, the green component is 0x60 and the blue component is 0x40.
2. Reassemble the color into 555 format. The formula for reducing a 24-bit RGB color into 555 format is shown here.

   ```
   ((red / 8) << 10) + ((blue / 8) << 5) + (green / 8)
   ```

   In this example, the value in 555 format is ((0x30 / 8) << 10) + ((0x60 / 8) << 5) + (0x40 / 8) = 6536.
3. The index value stored in position 6536 in the inverse color map table is the index of the color in the halftone palette that is a reasonable approximation to the color #306040.

## See also

[CreateHalftonePalette](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-createhalftonepalette)

[GetNearestColor](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-getnearestcolor)