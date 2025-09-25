# CreateGenericComposite function

## Description

Performs a generic composition of two monikers and supplies a pointer to the resulting composite moniker.

## Parameters

### `pmkFirst` [in, optional]

A pointer to the moniker to be composed to the left of the moniker that pmkRest points to. Can point to any kind of moniker, including a generic composite.

### `pmkRest` [in, optional]

A pointer to the moniker to be composed to the right of the moniker to which *pmkFirst* points. Can point to any kind of moniker compatible with the type of the *pmkRest* moniker, including a generic composite.

### `ppmkComposite` [out]

The address of an [IMoniker](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-imoniker)* pointer variable that receives the interface pointer to the composite moniker object that is the result of composing *pmkFirst* and *pmkRest*. This object supports the OLE composite moniker implementation of **IMoniker**. When successful, the function has called [AddRef](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-addref) on the moniker and the caller is responsible for calling [Release](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-release). If either *pmkFirst* or *pmkRest* are **NULL**, the supplied pointer is the one that is non-**NULL**. If both *pmkFirst* and *pmkRest* are **NULL**, or if an error occurs, the returned pointer is **NULL**.

## Return value

This function can return the standard return value E_OUTOFMEMORY, as well as the following values.

| Return code | Description |
| --- | --- |
| **S_OK** | The input monikers were composed successfully. |
| **MK_E_SYNTAX** | The two monikers could not be composed due to an error in the syntax of a path (for example, if both pmkFirst and pmkRest are file monikers based on absolute paths). |

## Remarks

**CreateGenericComposite** joins two monikers into one. The moniker classes being joined can be different, subject only to the rules of composition. Call this function only if you are writing a new moniker class by implementing the [IMoniker](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-imoniker) interface, within an implementation of [IMoniker::ComposeWith](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-imoniker-composewith) that includes generic composition capability.

Moniker providers should call [ComposeWith](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-imoniker-composewith) to compose two monikers together. Implementations of **ComposeWith** should (as do OLE implementations) attempt, when reasonable for the class, to perform non-generic compositions first, in which two monikers of the same class are combined. If this is not possible, the implementation can call **CreateGenericComposite** to do a generic composition, which combines two monikers of different classes, within the rules of composition. You can define new types of non-generic compositions if you write a new moniker class.

During the process of composing the two monikers, **CreateGenericComposite** makes all possible simplifications. Consider the example where *pmkFirst* is the generic composite moniker, A + B + C, and *pmkRest* is the generic composite moniker, C -1 + B -1 + Z (where C -1 is the inverse of C). The function first composes C to C -1, which composes to nothing. Then it composes B and B -1 to nothing. Finally, it composes A to Z, and supplies a pointer to the generic composite moniker, A + Z.

## See also

[IMoniker](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-imoniker)

[IMoniker::ComposeWith](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-imoniker-composewith)