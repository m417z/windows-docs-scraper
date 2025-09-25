# IWbemDecoupledRegistrar::Register

## Description

The
**IWbemDecoupledRegistrar::Register** method registers an object interface with WMI.

## Parameters

### `a_Flags` [in]

Reserved for future use.

### `a_Context` [in]

Reserved for future use.

### `a_User` [in]

String identifying the user for this registration.

### `a_Locale` [in]

String identifying the locale for this registration.

### `a_Scope` [in]

Object path representing the binding to a WMI provider registration object in a specified namespace. The scope object path can be **NULL**, indicating that the provider will support all namespaces.

### `a_Registration` [in]

Name of the provider being registered.

### `pIUnknown` [in]

Pointer to an object for particular registration. This interface will be queried to determine the interface support that the object is capable of servicing.

## Return value

This method returns an **HRESULT** indicating the status of the method call. The following list lists the value contained within an **HRESULT**.