# SPropValue structure

## Description

Do not use. Contains the property tag values.

## Members

### `ulPropTag`

Type: **ULONG**

Variable of type **ULONG** that specifies the property tag for the property. Property tags are 32-bit unsigned integers consisting of the property's unique identifier in the high-order 16 bits and the property's type in the low-order 16 bits.

### `dwAlignPad`

Type: **ULONG**

### `Value`

Union of data values, with the specific value dictated by the property type. The following text provides a list for each property type of the member of the union to be used and its associated data type.

#### i

Type: **short**

PT_I2 or PT_SHORT

#### l

Type: **LONG**

PT_LONG

#### ul

Type: **ULONG**

PT_LONG

#### flt

Type: **float**

PT_R4

#### dbl

Type: **double**

PT_DOUBLE

#### b

Type: **USHORT**

PT_BOOLEAN

#### cur

Type: **CURRENCY**

PT_CURRENCY

#### at

Type: **double**

PT_APPTIME

#### ft

Type: **FILETIME**

PT_SYSTIME

#### lpszA

Type: **LPSTR**

PT_STRING8

#### bin

Type: **[SBinary](https://learn.microsoft.com/previous-versions/office/developer/office-2007/cc815817(v=office.12))**

PT_BINARY

#### lpszW

Type: **LPWSTR**

PT_UNICODE

#### lpguid

Type: **LPGUID**

PT_CLSID

#### li

Type: **LARGE_INTEGER**

PT_I8

#### MVi

Type: **SShortArray**

PT_MV_I2

#### MVl

Type: **SLongArray**

PT_MV_LONG

#### MVflt

Type: **SRealArray**

PT_MV_R4

#### MVdbl

Type: **SDoubleArray**

PT_MV_DOUBLE

#### MVcur

Type: **SCurrencyArray**

PT_MV_CURRENCY

#### MVat

Type: **SAppTimeArray**

PT_MV_APPTIME

#### MVft

Type: **SDateTimeArray**

PT_MV_SYSTIME

#### MVbin

Type: **[SBinaryArray](https://learn.microsoft.com/previous-versions/office/developer/office-2007/cc815398(v=office.12))**

PT_MV_BINARY

#### MVszA

Type: **SLPSTRArray**

PT_MV_STRING8

#### MVszW

Type: **SWStringArray**

PT_MV_UNICODE

#### MVguid

Type: **SGuidArray**

PT_MV_CLSID

#### MVli

Type: **SLargeIntegerArray**

PT_MV_I8

#### err

Type: **SCODE**

PT_ERROR

#### x

Type: **LONG**

PT_NULL, PT_OBJECT (no usable value)

### `_PV`