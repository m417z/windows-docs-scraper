# PropVariantToInt16WithDefault function

## Description

Extracts the Int16 property value of a [PROPVARIANT](https://learn.microsoft.com/windows/desktop/api/propidl/ns-propidl-propvariant) structure. If no value currently exists, then specified default value is returned.

## Parameters

### `propvarIn` [in]

Type: **REFPROPVARIANT**

Reference to a source [PROPVARIANT](https://learn.microsoft.com/windows/desktop/api/propidl/ns-propidl-propvariant) structure.

### `iDefault` [in]

Type: **SHORT**

Specifies default property value, for use where no value currently exists.

## Return value

Type: **SHORT**

Returns the extracted **short** value, or default.

## Remarks

This helper function is used in places where the calling application expects a [PROPVARIANT](https://learn.microsoft.com/windows/desktop/api/propidl/ns-propidl-propvariant) to hold an **Int16** value and would like to use a default value if it does not. For instance, an application obtaining values from a property store can use this to safely extract the **SHORT** value for **Int16** properties.

If the source [PROPVARIANT](https://learn.microsoft.com/windows/desktop/api/propidl/ns-propidl-propvariant) has type **VT_I2**, this helper function extracts the **Int16** value. Otherwise, it attempts to convert the value in the **PROPVARIANT** structure into a **SHORT**. If the source **PROPVARIANT** has type **VT_EMPTY** or a conversion is not possible, then [PropVariantToInt16WithDefault](https://learn.microsoft.com/windows/desktop/api/propvarutil/nf-propvarutil-propvarianttoint16withdefault) will return the default provided by *iDefault*. See [PropVariantChangeType](https://learn.microsoft.com/windows/desktop/api/propvarutil/nf-propvarutil-propvariantchangetype) for a list of possible conversions.

## See also

[InitPropVariantFromInt16](https://learn.microsoft.com/windows/desktop/api/propvarutil/nf-propvarutil-initpropvariantfromint16)

[PropVariantChangeType](https://learn.microsoft.com/windows/desktop/api/propvarutil/nf-propvarutil-propvariantchangetype)

[PropVariantToInt16](https://learn.microsoft.com/windows/desktop/api/propvarutil/nf-propvarutil-propvarianttoint16)

[VariantToInt16](https://learn.microsoft.com/windows/desktop/api/propvarutil/nf-propvarutil-varianttoint16)