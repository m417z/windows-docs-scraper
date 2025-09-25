# LHashValOfName macro

## Description

Computes a hash value for a name.

## Parameters

### `lcid`

The LCID for the string.

### `szName`

The string whose hash value is to be computed.

## Remarks

This function is equivalent to [LHashValOfNameSys](https://learn.microsoft.com/previous-versions/windows/desktop/api/oleauto/nf-oleauto-lhashvalofnamesys). The header file OleAuto.h contains macros that define **LHashValOfName** as **LHashValOfNameSys**, with the target operating system (syskind) based on the build preprocessor flags.

**LHashValOfName** computes a 32-bit hash value for a name that can be passed to [ITypeComp::Bind](https://learn.microsoft.com/windows/desktop/api/oaidl/nf-oaidl-itypecomp-bind), [ITypeComp::BindType](https://learn.microsoft.com/previous-versions/windows/desktop/api/oaidl/nf-oaidl-itypecomp-bindtype), [ITypeLib::FindName](https://learn.microsoft.com/previous-versions/windows/desktop/api/oaidl/nf-oaidl-itypelib-findname), or [ITypeLib::IsName](https://learn.microsoft.com/previous-versions/windows/desktop/api/oaidl/nf-oaidl-itypelib-isname). The returned hash value is independent of the case of the characters in *szName*, as long as the language of the name is one of the languages supported by the OLE National Language Specification API. Any two strings that match when a case-insensitive comparison is done using any language produce the same hash value.