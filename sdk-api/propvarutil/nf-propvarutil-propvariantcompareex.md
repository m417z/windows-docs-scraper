# PropVariantCompareEx function

## Description

Extends [PropVariantCompare](https://learn.microsoft.com/windows/desktop/api/propvarutil/nf-propvarutil-propvariantcompare) by allowing the caller to compare two [PROPVARIANT](https://learn.microsoft.com/windows/desktop/api/propidl/ns-propidl-propvariant) structures based on specified comparison units and flags.

## Parameters

### `propvar1` [in]

Type: **REFPROPVARIANT**

Reference to the first [PROPVARIANT](https://learn.microsoft.com/windows/desktop/api/propidl/ns-propidl-propvariant) structure.

### `propvar2` [in]

Type: **REFPROPVARIANT**

Reference to the second [PROPVARIANT](https://learn.microsoft.com/windows/desktop/api/propidl/ns-propidl-propvariant) structure.

### `unit` [in]

Type: **[PROPVAR_COMPARE_UNIT](https://learn.microsoft.com/windows/desktop/api/propvarutil/ne-propvarutil-propvar_compare_unit)**

Specifies, where appropriate, one of the comparison units defined in [PROPVAR_COMPARE_UNIT](https://learn.microsoft.com/windows/desktop/api/propvarutil/ne-propvarutil-propvar_compare_unit).

### `flags` [in]

Type: **PROPVAR_COMPARE_FLAGS**

Specifies one of the following:

#### PVCF_DEFAULT (0x00000000)

When comparing strings, use [StrCmpLogical](https://learn.microsoft.com/windows/desktop/api/shlwapi/nf-shlwapi-strcmplogicalw).

#### PVCF_TREATEMPTYASGREATERTHAN (0x00000001)

Regard empty or null values as greater than non-empty values. This value can be OR-ed with any other value.

#### PVCF_USESTRCMP (0x00000002)

When comparing strings, use [StrCmp](https://learn.microsoft.com/windows/desktop/api/shlwapi/nf-shlwapi-strcmpw).

#### PVCF_USESTRCMPC (0x00000004)

When comparing strings, use [StrCmpC](https://learn.microsoft.com/windows/desktop/api/shlwapi/nf-shlwapi-strcmpca).

#### PVCF_USESTRCMPI (0x00000008)

When comparing strings, use [StrCmpI](https://learn.microsoft.com/windows/desktop/api/shlwapi/nf-shlwapi-strcmpiw).

#### PVCF_USESTRCMPIC (0x00000010)

When comparing strings, use [StrCmpIC](https://learn.microsoft.com/windows/desktop/api/shlwapi/nf-shlwapi-strcmpica).

## Return value

Type: **INT**

* Returns 1 if *propvar1* is greater than *propvar2*
* Returns 0 if *propvar1* equals *propvar2*
* Returns -1 if *propvar1* is less than *propvar2*

## Remarks

This function does not compare all types; only selected types are currently comparable.

By default, VT_NULL / VT_EMPTY / 0-element vectors are considered to be less than any other vartype.

If the vartypes are different, this function attempts to convert *propvar2* to the vartype of *propvar1* before comparing them.

**Note** Behavior of this function, and therefore the results it returns, can change from release to release. It should not be used for canonical sorting applications.