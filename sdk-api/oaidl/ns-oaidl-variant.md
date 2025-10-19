# VARIANT structure

## Description

**VARIANTARG** describes arguments passed within DISPPARAMS, and **VARIANT** to specify variant data that cannot be passed by reference.

When a variant refers to another variant by using the VT_VARIANT | VT_BYREF vartype, the variant being referred to cannot also be of type VT_VARIANT | VT_BYREF. VARIANTs can be passed by value, even if VARIANTARGs cannot.

## Members

### `__VARIANT_NAME_1`

### `__VARIANT_NAME_1.__VARIANT_NAME_2`

Type: **struct __tagVARIANT**

### `__VARIANT_NAME_1.__VARIANT_NAME_2.vt`

Type: **VARTYPE**

The type of data in the union.

### `__VARIANT_NAME_1.__VARIANT_NAME_2.wReserved1`

Type: **WORD**

Reserved.

### `__VARIANT_NAME_1.__VARIANT_NAME_2.wReserved2`

Type: **WORD**

Reserved.

### `__VARIANT_NAME_1.__VARIANT_NAME_2.wReserved3`

Type: **WORD**

Reserved.

### `__VARIANT_NAME_1.__VARIANT_NAME_2.__VARIANT_NAME_3`

###### __VARIANT_NAME_2.__VARIANT_NAME_3.bool

Type: **_VARIANT_BOOL**

A 16-bit Boolean value. A value of 0xFFFF (all bits 1) indicates true; a value of 0 (all bits 0) indicates false. No other values are valid.

###### __VARIANT_NAME_2.__VARIANT_NAME_3.pbool

Type: **_VARIANT_BOOL***

A reference to a 16-bit Boolean value.

### `__VARIANT_NAME_1.__VARIANT_NAME_2.__VARIANT_NAME_3.llVal`

Type: **LONGLONG**

An 8-byte integer value.

### `__VARIANT_NAME_1.__VARIANT_NAME_2.__VARIANT_NAME_3.lVal`

Type: **LONG**

A 4-byte integer value.

### `__VARIANT_NAME_1.__VARIANT_NAME_2.__VARIANT_NAME_3.bVal`

Type: **BYTE**

An unsigned 1-byte character.

### `__VARIANT_NAME_1.__VARIANT_NAME_2.__VARIANT_NAME_3.iVal`

Type: **SHORT**

A 2-byte integer value.

### `__VARIANT_NAME_1.__VARIANT_NAME_2.__VARIANT_NAME_3.fltVal`

Type: **FLOAT**

A 4-byte real value.

### `__VARIANT_NAME_1.__VARIANT_NAME_2.__VARIANT_NAME_3.dblVal`

Type: **DOUBLE**

An 8-byte real value.

### `__VARIANT_NAME_1.__VARIANT_NAME_2.__VARIANT_NAME_3.boolVal`

Type: **VARIANT_BOOL**

A 16-bit Boolean value. A value of 0xFFFF (all bits 1) indicates true; a value of 0 (all bits 0) indicates false. No other values are valid.

### `__VARIANT_NAME_1.__VARIANT_NAME_2.__VARIANT_NAME_3.scode`

Type: **SCODE**

An SCODE value.

### `__VARIANT_NAME_1.__VARIANT_NAME_2.__VARIANT_NAME_3.cyVal`

Type: **CY**

A currency value.

### `__VARIANT_NAME_1.__VARIANT_NAME_2.__VARIANT_NAME_3.date`

Type: **DATE**

A date and time value. Dates are represented as double-precision numbers, where midnight, January 1, 1900 is 2.0, January 2, 1900 is 3.0, and so on.

The date can be converted to and from an MS-DOS representation using [VariantTimeToDosDateTime](https://learn.microsoft.com/previous-versions/windows/desktop/api/oleauto/nf-oleauto-varianttimetodosdatetime).

### `__VARIANT_NAME_1.__VARIANT_NAME_2.__VARIANT_NAME_3.bstrVal`

Type: **BSTR**

A string value.

### `__VARIANT_NAME_1.__VARIANT_NAME_2.__VARIANT_NAME_3.punkVal`

Type: **IUnknown***

A pointer to an object that implements the [IUnknown](https://learn.microsoft.com/windows/desktop/api/unknwn/nn-unknwn-iunknown) interface.

### `__VARIANT_NAME_1.__VARIANT_NAME_2.__VARIANT_NAME_3.pdispVal`

Type: **IDispatch***

A pointer to an object was specified.

### `__VARIANT_NAME_1.__VARIANT_NAME_2.__VARIANT_NAME_3.parray`

Type: **SAFEARRAY***

A safe array descriptor, which describes the dimensions, size, and in-memory location of the array.

### `__VARIANT_NAME_1.__VARIANT_NAME_2.__VARIANT_NAME_3.pbVal`

Type: **BYTE***

A reference to an unsigned 1-byte character.

### `__VARIANT_NAME_1.__VARIANT_NAME_2.__VARIANT_NAME_3.piVal`

Type: **SHORT***

A reference to a 2-byte integer value.

### `__VARIANT_NAME_1.__VARIANT_NAME_2.__VARIANT_NAME_3.plVal`

Type: **LONG***

A reference to a 4-byte integer value.

### `__VARIANT_NAME_1.__VARIANT_NAME_2.__VARIANT_NAME_3.pllVal`

Type: **LONGLONG***

A reference to an 8-byte integer value.

### `__VARIANT_NAME_1.__VARIANT_NAME_2.__VARIANT_NAME_3.pfltVal`

Type: **FLOAT***

A reference to a 4-byte real value.

### `__VARIANT_NAME_1.__VARIANT_NAME_2.__VARIANT_NAME_3.pdblVal`

Type: **DOUBLE***

A reference to an 8-byte real value.

### `__VARIANT_NAME_1.__VARIANT_NAME_2.__VARIANT_NAME_3.pboolVal`

Type: **VARIANT_BOOL***

A reference to a 16-bit Boolean value.

### `__VARIANT_NAME_1.__VARIANT_NAME_2.__VARIANT_NAME_3.pscode`

Type: **SCODE***

A reference to an SCODE value.

### `__VARIANT_NAME_1.__VARIANT_NAME_2.__VARIANT_NAME_3.pcyVal`

Type: **CY***

A reference to a currency value.

### `__VARIANT_NAME_1.__VARIANT_NAME_2.__VARIANT_NAME_3.pdate`

Type: **DATE***

A reference to a date and time value. Dates are represented as double-precision numbers, where midnight, January 1, 1900 is 2.0, January 2, 1900 is 3.0, and so on.

### `__VARIANT_NAME_1.__VARIANT_NAME_2.__VARIANT_NAME_3.pbstrVal`

Type: **BSTR***

A reference to a string value.

### `__VARIANT_NAME_1.__VARIANT_NAME_2.__VARIANT_NAME_3.ppunkVal`

Type: **IUnknown****

A reference to an [IUnknown](https://learn.microsoft.com/windows/desktop/api/unknwn/nn-unknwn-iunknown) interface pointer.

### `__VARIANT_NAME_1.__VARIANT_NAME_2.__VARIANT_NAME_3.ppdispVal`

Type: **IDispatch****

A reference to an object pointer.

### `__VARIANT_NAME_1.__VARIANT_NAME_2.__VARIANT_NAME_3.pparray`

### `__VARIANT_NAME_1.__VARIANT_NAME_2.__VARIANT_NAME_3.pvarVal`

### `__VARIANT_NAME_1.__VARIANT_NAME_2.__VARIANT_NAME_3.byref`

Type: **PVOID**

A generic value.

### `__VARIANT_NAME_1.__VARIANT_NAME_2.__VARIANT_NAME_3.cVal`

Type: **CHAR**

A 1-byte character value.

### `__VARIANT_NAME_1.__VARIANT_NAME_2.__VARIANT_NAME_3.uiVal`

Type: **USHORT**

An unsigned 2-byte integer value.

### `__VARIANT_NAME_1.__VARIANT_NAME_2.__VARIANT_NAME_3.ulVal`

Type: **ULONG**

An unsigned 4-byte integer value.

### `__VARIANT_NAME_1.__VARIANT_NAME_2.__VARIANT_NAME_3.ullVal`

Type: **ULONGLONG**

An unsigned 8-byte integer value.

### `__VARIANT_NAME_1.__VARIANT_NAME_2.__VARIANT_NAME_3.intVal`

Type: **INT**

An integer value.

### `__VARIANT_NAME_1.__VARIANT_NAME_2.__VARIANT_NAME_3.uintVal`

Type: **UINT**

An unsigned integer value.

### `__VARIANT_NAME_1.__VARIANT_NAME_2.__VARIANT_NAME_3.pdecVal`

Type: **DECIMAL***

A decimal value, which is stored as 96-bit (12-byte) unsigned integers scaled by a variable power of 10.

### `__VARIANT_NAME_1.__VARIANT_NAME_2.__VARIANT_NAME_3.pcVal`

Type: **CHAR***

A reference to a 1-byte character value.

### `__VARIANT_NAME_1.__VARIANT_NAME_2.__VARIANT_NAME_3.puiVal`

Type: **USHORT***

A reference to an unsigned 2-byte integer value.

### `__VARIANT_NAME_1.__VARIANT_NAME_2.__VARIANT_NAME_3.pulVal`

Type: **ULONG***

A reference to an unsigned 4-byte integer value.

### `__VARIANT_NAME_1.__VARIANT_NAME_2.__VARIANT_NAME_3.pullVal`

Type: **ULONGLONG***

A reference to an unsigned 8-byte integer value.

### `__VARIANT_NAME_1.__VARIANT_NAME_2.__VARIANT_NAME_3.pintVal`

Type: **INT***

A reference to an integer value.

### `__VARIANT_NAME_1.__VARIANT_NAME_2.__VARIANT_NAME_3.puintVal`

Type: **UINT***

A reference to an unsigned integer value.

### `__VARIANT_NAME_1.__VARIANT_NAME_2.__VARIANT_NAME_3.__VARIANT_NAME_4`

Type: **struct __tagBRECORD**

### `__VARIANT_NAME_1.__VARIANT_NAME_2.__VARIANT_NAME_3.__VARIANT_NAME_4.pvRecord`

Type: **PVOID**

A reference to a database record.

### `__VARIANT_NAME_1.__VARIANT_NAME_2.__VARIANT_NAME_3.__VARIANT_NAME_4.pRecInfo`

Type: **[IRecordInfo](https://learn.microsoft.com/previous-versions/windows/desktop/api/oaidl/nn-oaidl-irecordinfo)***

A reference to a UDT.

### `__VARIANT_NAME_1.decVal`

Type: **DECIMAL**

A decimal value.