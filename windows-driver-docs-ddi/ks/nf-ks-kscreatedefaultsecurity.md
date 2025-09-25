# KsCreateDefaultSecurity function

## Description

The **KsCreateDefaultSecurity** function creates a security descriptor with default security, optionally inheriting parameters from a parent security descriptor.

## Parameters

### `ParentSecurity` [in, optional]

Points to the parent object's security descriptor, describing inherited security parameters. This argument is optional.

### `DefaultSecurity` [out]

Points to the place in which to put the returned default security descriptor.

## Return value

**KsCreateDefaultSecurity** returns STATUS_SUCCESS if the operation is successful, else a resource or assignment error.

## Remarks

**KsCreateDefaultSecurity** is used to initialize subobjects that do not have any stored security.