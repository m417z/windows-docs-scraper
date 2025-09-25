# OLEVERB structure

## Description

Defines a verb that an object supports. The [IOleObject::EnumVerbs](https://learn.microsoft.com/windows/desktop/api/oleidl/nf-oleidl-ioleobject-enumverbs) method creates an enumerator that can enumerate these structures for an object, and supplies a pointer to the enumerator's [IEnumOLEVERB](https://learn.microsoft.com/windows/desktop/api/oleidl/nn-oleidl-ienumoleverb).

## Members

### `lVerb`

Integer identifier associated with this verb.

### `lpszVerbName`

Pointer to a string that contains the verb's name.

### `fuFlags`

In Windows, a group of flags taken from the flag constants beginning with MF_ defined in [AppendMenu](https://learn.microsoft.com/windows/desktop/menurc/u). Containers should use these flags in building an object's verb menu. All Flags defined in **AppendMenu** are supported except for MF_BITMAP, MF_OWNERDRAW, and MF_POPUP.

### `grfAttribs`

Combination of the verb attributes in the [OLEVERBATTRIB](https://learn.microsoft.com/windows/desktop/api/oleidl/ne-oleidl-oleverbattrib) enumeration.

## See also

[IEnumOLEVERB](https://learn.microsoft.com/windows/desktop/api/oleidl/nn-oleidl-ienumoleverb)

[IOleObject::EnumVerbs](https://learn.microsoft.com/windows/desktop/api/oleidl/nf-oleidl-ioleobject-enumverbs)