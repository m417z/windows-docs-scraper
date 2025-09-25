# IGPMGPO::GetSecurityDescriptor

## Description

Retrieves a pointer to an **IDispatch** interface from which the security descriptor for the Group Policy object (GPO) can be retrieved. For script programmers, this method returns a reference to an
[IADsSecurityDescriptor](https://learn.microsoft.com/windows/desktop/api/iads/nn-iads-iadssecuritydescriptor) object.

## Parameters

### `lFlags` [in]

Specifies a set of bit flags. Use this parameter to specify the parts of the security descriptor to retrieve. The following values are valid.

#### OWNER_SECURITY_INFORMATION (1)

Owner identifier of the object.

#### GROUP_SECURITY_INFORMATION (2)

Primary group identifier.

#### DACL_SECURITY_INFORMATION (4)

Discretionary access control list (DACL) of the object.

#### SACL_SECURITY_INFORMATION (8)

System access control list (ACL) of the object.

### `ppSD` [out]

Address of a pointer to an **IDispatch** interface. You can call the [IUnknown::QueryInterface](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-queryinterface(q)) method to obtain a pointer to the [IADsSecurityDescriptor](https://learn.microsoft.com/windows/desktop/api/iads/nn-iads-iadssecuritydescriptor) interface on the security descriptor of the GPO.

## Return value

### C++

Returns **S_OK** if successful. Returns a failure code if an error occurs.

### JScript

Returns a reference to an
[IADsSecurityDescriptor](https://learn.microsoft.com/windows/desktop/api/iads/nn-iads-iadssecuritydescriptor) object.

### VB

Returns a reference to an
[IADsSecurityDescriptor](https://learn.microsoft.com/windows/desktop/api/iads/nn-iads-iadssecuritydescriptor) object.

## Remarks

For more information about security descriptors, ACLs, and the security model for controlling access to Windows-based objects, see [Access Control](https://learn.microsoft.com/windows/desktop/SecAuthZ/access-control).

## See also

[IGPMGPO](https://learn.microsoft.com/previous-versions/windows/desktop/api/gpmgmt/nn-gpmgmt-igpmgpo)