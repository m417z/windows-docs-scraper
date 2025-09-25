## Description

A support structure used in the [MI_Context](https://learn.microsoft.com/windows/desktop/api/mi/ns-mi-mi_context)
structure. Use the functions with the name prefix "MI_Context_" to manipulate these
structures.

## Members

### `Canceled`

Determines whether the operation has been canceled. See
[MI_Context_Canceled](https://learn.microsoft.com/previous-versions/windows/desktop/api/mi/nf-mi-mi_context_canceled).

### `ConstructInstance`

Initializes an instance. See
[MI_Context_ConstructInstance](https://learn.microsoft.com/previous-versions/windows/desktop/api/mi/nf-mi-mi_context_constructinstance).

### `ConstructParameters`

Initialize a parameters instance. See
[MI_Context_ConstructParameters](https://learn.microsoft.com/previous-versions/windows/desktop/api/mi/nf-mi-mi_context_constructparameters).

### `GetCustomOption`

Gets the specified provider custom option. See
[MI_Context_GetCustomOption](https://learn.microsoft.com/previous-versions/windows/desktop/api/mi/nf-mi-mi_context_getcustomoption).

### `GetCustomOptionAt`

Gets the provider's custom option at the specified index. See
[MI_Context_GetCustomOptionAt](https://learn.microsoft.com/previous-versions/windows/desktop/api/mi/nf-mi-mi_context_getcustomoptionat).

### `GetCustomOptionCount`

Gets the count of defined provider custom options. See
[MI_Context_GetCustomOptionCount](https://learn.microsoft.com/previous-versions/windows/desktop/api/mi/nf-mi-mi_context_getcustomoptioncount).

### `GetLocalSession`

Gets the local session allowing the provider to communicate with the CIM server. See
[MI_Context_GetLocalSession](https://learn.microsoft.com/previous-versions/windows/desktop/api/mi/nf-mi-mi_context_getlocalsession).

### `GetLocale`

Returns the locale of the given type. See
[MI_Context_GetLocale](https://learn.microsoft.com/previous-versions/windows/desktop/api/mi/nf-mi-mi_context_getlocale).

### `GetNumberOption`

Gets the specified provider custom option. See
[MI_Context_GetNumberOption](https://learn.microsoft.com/previous-versions/windows/desktop/api/mi/nf-mi-mi_context_getnumberoption).

### `GetStringOption`

Gets the specified provider custom option. See
[MI_Context_GetStringOption](https://learn.microsoft.com/previous-versions/windows/desktop/api/mi/nf-mi-mi_context_getstringoption).

### `NewDynamicInstance`

Creates a new dynamic instance of the class whose name is given by className. See
[MI_Context_NewDynamicInstance](https://learn.microsoft.com/previous-versions/windows/desktop/api/mi/nf-mi-mi_context_newdynamicinstance).

### `NewInstance`

Creates a new instance of the class given by the classDecl parameter. See
[MI_Context_NewInstance](https://learn.microsoft.com/previous-versions/windows/desktop/api/mi/nf-mi-mi_context_newinstance).

### `NewParameters`

Creates a new instance of the method given by methodDecl. See
[MI_Context_NewParameters](https://learn.microsoft.com/previous-versions/windows/desktop/api/mi/nf-mi-mi_context_newparameters).

### `PostCimError`

Posts a return code and an error message to the server in response to a request. See
[MI_Context_PostCimError](https://learn.microsoft.com/previous-versions/windows/desktop/api/mi/nf-mi-mi_context_postcimerror).

### `PostError`

Providers call this function to post a return code to the client in response to a request. See
[MI_Context_PostError](https://learn.microsoft.com/previous-versions/windows/desktop/api/mi/nf-mi-mi_context_posterror).

### `PostIndication`

Posts an indication to the server in response to a request. See
[MI_Context_PostIndication](https://learn.microsoft.com/previous-versions/windows/desktop/api/mi/nf-mi-mi_context_postindication).

### `PostInstance`

Providers call this function to post an instance to the server in response to a request. See
[MI_Context_PostInstance](https://learn.microsoft.com/previous-versions/windows/desktop/api/mi/nf-mi-mi_context_postinstance).

### `PostResult`

Providers call this function to post a return code to the server in response to a request. See
[MI_Context_PostResult](https://learn.microsoft.com/previous-versions/windows/desktop/api/mi/nf-mi-mi_context_postresult).

#### - PostTerminatingError

Posts a return code and an error message to the server in response to a request.

### `PromptUser`

Sends a prompt message to the client querying whether to continue the operation or cancel it. See
[MI_Context_PromptUser](https://learn.microsoft.com/previous-versions/windows/desktop/api/mi/nf-mi-mi_context_promptuser).

### `RefuseUnload`

Tells the provider infrastructure to not unload the provider. See
[MI_Context_RefuseUnload](https://learn.microsoft.com/previous-versions/windows/desktop/api/mi/nf-mi-mi_context_refuseunload).

### `RegisterCancel`

Registers a callback that is invoked when the operation is canceled. See
[MI_Context_RegisterCancel](https://learn.microsoft.com/previous-versions/windows/desktop/api/mi/nf-mi-mi_context_registercancel).

### `RequestUnload`

Requests to unload the module or the provider (depending on the location of invocation). See
[MI_Context_RequestUnload](https://learn.microsoft.com/previous-versions/windows/desktop/api/mi/nf-mi-mi_context_requestunload).

### `SetStringOption`

Sets a context-specific option. See
[MI_Context_SetStringOption](https://learn.microsoft.com/previous-versions/windows/desktop/api/mi/nf-mi-mi_context_setstringoption).

### `ShouldContinue`

Queries the client to determine if an operation should continue. See
[MI_Context_ShouldContinue](https://learn.microsoft.com/previous-versions/windows/desktop/api/mi/nf-mi-mi_context_shouldcontinue).

### `ShouldProcess`

Queries the client to determine if an operation should continue. See
[MI_Context_ShouldProcess](https://learn.microsoft.com/previous-versions/windows/desktop/api/mi/nf-mi-mi_context_shouldprocess).

### `WriteCimError`

Sends a CIM error instance to the client. See
[MI_Context_WriteCimError](https://learn.microsoft.com/previous-versions/windows/desktop/api/mi/nf-mi-mi_context_writecimerror).

### `WriteError`

This function has been deprecated. Use
[MI_Context_WriteError](https://learn.microsoft.com/previous-versions/windows/desktop/api/mi/nf-mi-mi_context_writeerror) instead.

Sends an error code and error message to the client. See
[MI_Context_WriteError](https://learn.microsoft.com/previous-versions/windows/desktop/api/mi/nf-mi-mi_context_writeerror).

### `WriteMessage`

Sends an operational message to the client. See
[MI_Context_WriteMessage](https://learn.microsoft.com/previous-versions/windows/desktop/api/mi/nf-mi-mi_context_writemessage).

### `WriteProgress`

Sends a progress message to the client. See
[MI_Context_WriteProgress](https://learn.microsoft.com/previous-versions/windows/desktop/api/mi/nf-mi-mi_context_writeprogress).

### `WriteStreamParameter`

Sends streamed parameter data to the requestor. See
[MI_Context_WriteStreamParameter](https://learn.microsoft.com/previous-versions/windows/desktop/api/mi/nf-mi-mi_context_writestreamparameter).