# ITsSbProvider::CreateEnvironmentObject

## Description

Creates an [ITsSbEnvironment](https://learn.microsoft.com/windows/desktop/api/sbtsv/nn-sbtsv-itssbenvironment) environment object.

## Parameters

### `Name` [in]

A **BSTR** variable that contains the name of the object to create.

### `ServerWeight` [in]

A **DWORD** variable that contains the server weight of the object to create.

### `ppEnvironment` [out]

A pointer to a pointer to the newly created environment object. When you have finished using the object, release it by calling the [Release](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-release) method.

## Return value

This method can return one of these values.

If the method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** value that indicates the error. Possible values include, but are not limited to, those in the following list.

## Remarks

Plug-ins can use this method to create an environment object.

## See also

[ITsSbEnvironment](https://learn.microsoft.com/windows/desktop/api/sbtsv/nn-sbtsv-itssbenvironment)

[ITsSbProvider](https://learn.microsoft.com/windows/desktop/api/sbtsv/nn-sbtsv-itssbprovider)