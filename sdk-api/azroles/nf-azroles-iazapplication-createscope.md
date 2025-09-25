# IAzApplication::CreateScope

## Description

The **CreateScope** method creates an [IAzScope](https://learn.microsoft.com/windows/desktop/api/azroles/nn-azroles-iazscope) object with the specified name.

## Parameters

### `bstrScopeName` [in]

Name for the new [IAzScope](https://learn.microsoft.com/windows/desktop/api/azroles/nn-azroles-iazscope) object.

### `varReserved` [in, optional]

Reserved for future use.

### `ppScope` [out]

A pointer to a pointer to the created [IAzScope](https://learn.microsoft.com/windows/desktop/api/azroles/nn-azroles-iazscope) object.

## Return value

 If the method succeeds, the method returns S_OK.

Any other **HRESULT** value indicates that the operation failed.

## Remarks

You must call the [IAzScope::Submit](https://learn.microsoft.com/windows/desktop/api/azroles/nf-azroles-iazscope-submit) method to persist any changes made to the returned object.

The returned [IAzScope](https://learn.microsoft.com/windows/desktop/api/azroles/nn-azroles-iazscope) object is an immediate child object of the [IAzApplication](https://learn.microsoft.com/windows/desktop/api/azroles/nn-azroles-iazapplication) object.