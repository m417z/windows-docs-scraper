# SecurityProperty::GetOriginalCallerName

## Description

Retrieves the user name associated with the base process that initiated the sequence of calls from which the call into the current object originated.

## Parameters

### `bstrUserName` [out]

A reference to the user name associated with the base process that initiated the sequence of calls from which the call into the current object originated.

## Return value

This method can return the standard return values E_INVALIDARG, E_OUTOFMEMORY, E_UNEXPECTED, E_FAIL, and S_OK.

## Remarks

Generally, an object's original caller is the same process as its original creator. The only situation in which the original caller and the original creator would be different is one in which the original creator passes a reference to another process and the other process initiates the call sequence.

The following scenario illustrates the functionality of this method:

1. Base process 1, running on server A as user A, creates object X, on server B, running as user B.
2. Then base process 1 passes its reference on object X to base process 2, running on server D as user D.
3. Base process 2 uses that reference to call into object X.
4. Object X then calls into object Y, running on server C. If object Y then calls **GetOriginalCallerName**, the name of user D is returned, not user A, who originally created the object.

The path to the original caller is broken if any object along the chain was created by some other means than [ObjectContext::CreateInstance](https://learn.microsoft.com/windows/desktop/api/comsvcs/nf-comsvcs-objectcontext-createinstance) or [ITransactionContext::CreateInstance](https://learn.microsoft.com/windows/desktop/api/comsvcs/nf-comsvcs-itransactioncontext-createinstance). For example, if base process 1 uses [CoCreateInstance](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cocreateinstance) to create object X, when object Y calls **GetOriginalCallerName**, the name it gets back will be the name of user B, not user D. This is because the call sequence is traced back through the objects' context and COM+ can create a context only for an object that is created with either **ObjectContext::CreateInstance** or **ITransactionContext::CreateInstance**.

## See also

[SecurityProperty](https://learn.microsoft.com/windows/desktop/api/comsvcs/nn-comsvcs-securityproperty)