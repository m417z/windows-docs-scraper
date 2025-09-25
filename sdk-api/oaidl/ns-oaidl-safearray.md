# SAFEARRAY structure

## Description

Represents a safe array.

## Members

### `cDims`

The number of dimensions.

### `fFeatures`

Flags.

| Value | Meaning |
| --- | --- |
| **FADF_AUTO**<br><br>0x0001 | An array that is allocated on the stack. |
| **FADF_STATIC**<br><br>0x0002 | An array that is statically allocated. |
| **FADF_EMBEDDED**<br><br>0x0004 | An array that is embedded in a structure. |
| **FADF_FIXEDSIZE**<br><br>0x0010 | An array that may not be resized or reallocated. |
| **FADF_RECORD**<br><br>0x0020 | An array that contains records. When set, there will be a pointer to the [IRecordInfo](https://learn.microsoft.com/previous-versions/windows/desktop/api/oaidl/nn-oaidl-irecordinfo) interface at negative offset 4 in the array descriptor. |
| **FADF_HAVEIID**<br><br>0x0040 | An array that has an IID identifying interface. When set, there will be a GUID at negative offset 16 in the safe array descriptor. Flag is set only when FADF_DISPATCH or FADF_UNKNOWN is also set. |
| **FADF_HAVEVARTYPE**<br><br>0x0080 | An array that has a variant type. The variant type can be retrieved with [SafeArrayGetVartype](https://learn.microsoft.com/previous-versions/windows/desktop/automat/vartype). |
| **FADF_BSTR**<br><br>0x0100 | An array of BSTRs. |
| **FADF_UNKNOWN**<br><br>0x0200 | An array of IUnknown*. |
| **FADF_DISPATCH**<br><br>0x0400 | An array of IDispatch*. |
| **FADF_VARIANT**<br><br>0x0800 | An array of VARIANTs. |
| **FADF_RESERVED**<br><br>0xF008 | Bits reserved for future use. |

### `cbElements`

The size of an array element.

### `cLocks`

The number of times the array has been locked without a corresponding unlock.

### `pvData`

The data.

### `rgsabound`

One bound for each dimension.

## Remarks

The array **rgsabound** is stored with the left-most dimension in rgsabound[0] and the right-most dimension in `rgsabound[cDims - 1]`. If an array was specified in a C-like syntax as a [2][5], it would have two elements in the **rgsabound** vector. Element 0 has an **lLbound** of 0 and a **cElements** of 2. Element 1 has an **lLbound** of 0 and a **cElements** of 5.

The **fFeatures** flags describe attributes of an array that can affect how the array is released. The **fFeatures** field describes what type of data is stored in the **SAFEARRAY** and how the array is allocated. This allows freeing the array without referencing its containing variant.

#### Thread Safety

All public static members of the **SAFEARRAY** data type are thread safe. Instance members are not guaranteed to be thread safe.

For example, consider an application that uses the [SafeArrayLock](https://learn.microsoft.com/previous-versions/windows/desktop/api/oleauto/nf-oleauto-safearraylock) and [SafeArrayUnlock](https://learn.microsoft.com/previous-versions/windows/desktop/api/oleauto/nf-oleauto-safearrayunlock) functions. If these functions are called concurrently from different threads on the same **SAFEARRAY** data type instance, an inconsistent lock count may be created. This will eventually cause the **SafeArrayUnlock** function to return E_UNEXPECTED. You can prevent this by providing your own synchronization code.