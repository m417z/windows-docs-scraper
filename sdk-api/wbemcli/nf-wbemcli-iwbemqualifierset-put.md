# IWbemQualifierSet::Put

## Description

The **IWbemQualifierSet::Put** method writes the named qualifier and value. The new qualifier overwrites the previous value of the same name. If the qualifier does not exist, it is created.

Sometimes it is not possible to write the value of a qualifier, for example, if the qualifier is propagated from another object. Typically, propagated qualifiers are read-only, but they can be overridden. For more information, see
[Qualifier Flavors](https://learn.microsoft.com/windows/desktop/WmiSdk/qualifier-flavors).

When using the [Key](https://learn.microsoft.com/windows/desktop/WmiSdk/standard-qualifiers) qualifier, it is not necessary to specify any flavors or propagation rules.

The user may not create qualifiers with names that begin or end with an underscore (_). This is reserved for system classes and properties.

## Parameters

### `wszName` [in]

Name of the qualifier that is being written. The pointer is treated as read-only.

### `pVal` [in]

Cannot be **NULL**. This must point to a valid **VARIANT** that contains the qualifier value to be written. The pointer is treated as read-only. It is the caller's responsibility to call [VariantClear](https://learn.microsoft.com/previous-versions/windows/desktop/api/oleauto/nf-oleauto-variantclear) on this pointer after the value is not required.

Only variants and arrays of type **VT_I4**, **VT_R8**, **VT_BSTR**, **VT_BOOL** are supported.

### `lFlavor` [in]

Desired qualifier flavors for this qualifier. The following list lists the appropriate constants for *lFlavor*. The default value is zero (0).

#### WBEM_FLAVOR_OVERRIDABLE (0 (0x0))

The qualifier value can be overridden in a derived class or an instance. This is the default. Using this constant is the same as using the **EnableOverride** flag.

#### WBEM_FLAVOR_FLAG_PROPAGATE_TO_INSTANCE (1 (0x1))

The qualifier is propagated to instances. Using this constant is the same as using the **ToInstance** flag.

#### WBEM_FLAVOR_FLAG_PROPAGATE_TO_DERIVED_CLASS (2 (0x2))

The qualifier is propagated to derived classes. Using this constant is the same as using the **ToSubClass** flag.

#### WBEM_FLAVOR_NOT_OVERRIDABLE (16 (0x10))

The qualifier value cannot be overridden in a derived class or an instance. Using this constant is the same as using the **DisableOverride** flag.

#### WBEM_FLAVOR_AMENDED (128 (0x80))

The qualifier is localized. Using this constant is the same as using the **Amended** flag.

## Return value

This method returns an **HRESULT** that indicates the status of the method call. The following list lists the value contained within an **HRESULT**.

## See also

[Qualifier Flavors](https://learn.microsoft.com/windows/desktop/WmiSdk/qualifier-flavors)