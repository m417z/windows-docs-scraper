# IWbemQualifierSet::GetNames

## Description

The
**IWbemQualifierSet::GetNames** method retrieves the names of all of the qualifiers available from the current object or property. Alternately, depending on the filter value of *IFlags*, this method retrieves the names of certain qualifiers.

You can access these qualifiers by name, using
[IWbemQualifierSet::Get](https://learn.microsoft.com/windows/desktop/api/wbemcli/nf-wbemcli-iwbemqualifierset-get) for each name. It is not an error for any given object to have zero qualifiers, so the number of strings in *pstrNames* on return can be 0, even though **WBEM_S_NO_ERROR** returns.

## Parameters

### `lFlags` [in]

One of the following constants.

#### 0 (Zero)

Return the names of all qualifiers.

#### WBEM_FLAG_LOCAL_ONLY

Return only the names of qualifiers specific to the current property or object. If the current qualifiers set refers to a property, return only the qualifiers specific to the property (including overrides), and not those qualifiers propagated from the class definition. If the current qualifiers set refers to an instance, return only instance-specific qualifier names. If the current qualifiers set refers to a class, return only qualifiers specific to the class being derived.

#### WBEM_FLAG_PROPAGATED_ONLY

Return only the names of qualifiers propagated from another object. For example, if the current qualifier set refers to a property, return only the qualifiers propagated to this property from the class definition, and not those from the property itself. If the current qualifier set refers to an instance, return only those qualifiers propagated from the class definition. If the current qualifier set refers to a class, return only those qualifier names inherited from the parent classes.

### `pNames` [out]

A new **SAFEARRAY** is created that contains the requested names.

In all cases where no error is returned, a new array is created and *pstrNames* is set to point to it. This occurs even though the resulting array has zero elements. On error, a new **SAFEARRAY** is not returned.

## Return value

This method returns an **HRESULT** indicating the status of the method call. The following list lists the value contained within an **HRESULT**.

## Remarks

For an example of using **SAFEARRAY**s of **BSTR**s, see
[Retrieving Part of a WMI Instance](https://learn.microsoft.com/windows/desktop/WmiSdk/retrieving-part-of-an-instance).

## See also

[IWbemQualifierSet](https://learn.microsoft.com/windows/desktop/api/wbemcli/nn-wbemcli-iwbemqualifierset)

[IWbemQualifierSet::BeginEnumeration](https://learn.microsoft.com/windows/desktop/api/wbemcli/nf-wbemcli-iwbemqualifierset-beginenumeration)

[IWbemQualifierSet::Get](https://learn.microsoft.com/windows/desktop/api/wbemcli/nf-wbemcli-iwbemqualifierset-get)