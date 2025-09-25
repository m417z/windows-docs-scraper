# IWbemQualifierSet::BeginEnumeration

## Description

The
**IWbemQualifierSet::BeginEnumeration** method resets before there is an enumeration of all the qualifiers in the object. To enumerate all of the qualifiers on an object, this method must be called before the first call to
[IWbemQualifierSet::Next](https://learn.microsoft.com/windows/desktop/api/wbemcli/nf-wbemcli-iwbemqualifierset-next). The order in which qualifiers are enumerated is guaranteed to be invariant for a given instance of
[IWbemQualifierSet](https://learn.microsoft.com/windows/desktop/api/wbemcli/nn-wbemcli-iwbemqualifierset).

## Parameters

### `lFlags` [in]

Specifies the qualifiers to include in the enumeration. It must be one of the following constants.

#### 0 (Zero)

Return the names of all qualifiers.

#### WBEM_FLAG_LOCAL_ONLY

Return only the names of qualifiers specific to the current property or object. If the current qualifiers set refers to a property, return only the qualifiers specific to the property (including overrides), and not those qualifiers propagated from the class definition. If the current qualifiers set refers to an instance, return only instance-specific qualifier names. If the current qualifiers set refers to a class, return only qualifiers specific to the class being derived.

#### WBEM_FLAG_PROPAGATED_ONLY

Return only the names of qualifiers propagated from another object. For example, if the current qualifier set refers to a property, return only the qualifiers propagated to this property from the class definition, and not those from the property itself. If the current qualifier set refers to an instance, only return those qualifiers propagated from the class definition. If the current qualifier set refers to a class, only return those qualifier names inherited from the parent classes.

## Return value

This method returns an **HRESULT** indicating the status of the method call. The following list lists the value contained within an **HRESULT**.

## See also

[IWbemQualifierSet](https://learn.microsoft.com/windows/desktop/api/wbemcli/nn-wbemcli-iwbemqualifierset)

[IWbemQualifierSet::Next](https://learn.microsoft.com/windows/desktop/api/wbemcli/nf-wbemcli-iwbemqualifierset-next)