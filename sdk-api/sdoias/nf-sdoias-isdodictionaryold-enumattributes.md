# ISdoDictionaryOld::EnumAttributes

## Description

The
**EnumAttributes** method retrieves the values of the specified attributes.

## Parameters

### `Id` [in, out]

On input, a pointer to a [VARIANT](https://learn.microsoft.com/windows/desktop/api/oaidl/ns-oaidl-variant)
that specifies the attributes to enumerate. If the type of this
**VARIANT**, given by
**V_VT**(Id), is
**VT_EMPTY**,
**ISdoDictionaryOld::EnumAttributes**
enumerates all the attributes. If the type is **VT_I4**, then the value of the
**VARIANT** is the ID of the attribute
to enumerate.

On output, pointer to a
[SAFEARRAY](https://learn.microsoft.com/windows/desktop/api/oaidl/ns-oaidl-safearray) that contains the IDs of
the enumerated attributes.

### `pValues` [out]

Pointer to a
[SAFEARRAY](https://learn.microsoft.com/windows/desktop/api/oaidl/ns-oaidl-safearray) that contains
the values of the enumerated attributes.

## Return value

If the method succeeds the return value is **S_OK**.

If the method fails, the return value is one of the following error codes.

## Remarks

The parameters must not be **NULL**.

If VT(Id) = VT_EMPTY then all the attributes are returned. Otherwise VT(Id) should be **VT_I4** and only the attributes designed are retrieved.

When the method returns, Id is a [SAFEARRAY](https://learn.microsoft.com/windows/desktop/api/oaidl/ns-oaidl-safearray) of the Ids returned, and *pValues* is a **SAFEARRAY** of the values returned.

## See also

[ISdoDictionaryOld](https://learn.microsoft.com/windows/desktop/api/sdoias/nn-sdoias-isdodictionaryold)