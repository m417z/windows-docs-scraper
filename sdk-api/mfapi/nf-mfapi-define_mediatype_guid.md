# DEFINE_MEDIATYPE_GUID macro

## Description

Defines a media subtype GUID from a FOURCC code, **D3DFORMAT** value, or audio format type.

## Parameters

### `name`

The name of the GUID constant to be defined.

### `format`

A FOURCC code, D3DFORMAT value, or audio format type.

## Remarks

Media formats are often identified by a FOURCC code (such as 'AYUV'), **D3DFORMAT** value (such as D3DFMT_X8R8G8B8), or audio format type (such as WAVE_FORMAT_PCM). The **DEFINE_MEDIATYPE_GUID** macro defines a new GUID constant from one of these values. The resulting GUID can be used as a media subtype.

This macro invokes the **DEFINE_GUID** macro. The resulting GUID constant is declared `extern`, so the declaration must have global scope.

#### Examples

```cpp
#include <initguid.h>

// Declares a GUID named MFVideoFormat_ABCD_Format.
DEFINE_MEDIATYPE_GUID( MFVideoFormat_ABCD_Format, FCC('ABCD') );

```

## See also

[MF_MT_SUBTYPE](https://learn.microsoft.com/windows/desktop/medfound/mf-mt-subtype-attribute)

[Media Foundation Macros](https://learn.microsoft.com/windows/desktop/medfound/media-foundation-macros)

[Media Type GUIDs](https://learn.microsoft.com/windows/desktop/medfound/media-type-guids)

[Media Types](https://learn.microsoft.com/windows/desktop/medfound/media-types)