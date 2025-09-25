## Description

Specifies flags that alter device query behavior.

## Constants

### `DevQueryFlagNone`

No flags specified.

### `DevQueryFlagUpdateResults`

By default, queries do not receive updates. However, when a query registers for updates and specifies the **DevQueryFlagUpdateResults** flag, its result-set will continue to be updated by callbacks as changes in the system occurs that add or remove objects or change objects so that they now match, or no longer match the filter expression.

### `DevQueryFlagAllProperties`

Return all properties in all languages that exist for the object. See **DevQueryFlagLocalize** because it can modify this behavior.

### `DevQueryFlagLocalize`

When specified, properties of type [DEVPROP_TYPE_STRING_INDIRECT](https://learn.microsoft.com/windows-hardware/drivers/install/devprop-type-string-indirect) are resolved to the calling thread's UI language. Multi-language properties are retrieved in the preferred language of the calling application.

If used in conjunction with **DevQueryFlagAllProperties**, values for all property keys for the object will be fetched in the preferred language of the calling application.

### `DevQueryFlagAsyncClose`

This flag modifies the behavior of the [DevCloseObjectQuery](https://learn.microsoft.com/windows/win32/api/devquery/nf-devquery-devcloseobjectquery) function. When it is specified,
**DevCloseObjectQuery** will return immediately, but the callback function will continue to be invoked until a [DevQueryStateClosed](https://learn.microsoft.com/windows/win32/api/devquerydef/ne-devquerydef-dev_query_state) state change is received.

When **DevQueryFlagAsyncClose** is not specified, **DevCloseObjectQuery** will block until an outstanding callback returns, and no further callbacks will occur once the **DevCloseObjectQuery** returns.

In either case, a reference is held on the DLL where the callback function is implemented to ensure that it won't be unloaded while callbacks can still be invoked.

## Remarks

## See also