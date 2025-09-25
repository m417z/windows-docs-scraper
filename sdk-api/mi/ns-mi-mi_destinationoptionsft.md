# MI_DestinationOptionsFT structure

## Description

A support structure used in the [MI_DestinationOptions](https://learn.microsoft.com/windows/desktop/api/mi/ns-mi-mi_destinationoptions) structure. Use the functions with the name prefix "MI_DestinationOptions_" to manipulate these structures.

## Members

### `AddCredentials`

Used internally.

### `Clone`

Creates a copy of a [MI_DestinationOptions](https://learn.microsoft.com/windows/desktop/api/mi/ns-mi-mi_destinationoptions) structure. See [MI_DestinationOptions_Clone](https://learn.microsoft.com/previous-versions/windows/desktop/api/mi/nf-mi-mi_destinationoptions_clone).

### `Delete`

Deletes the destination options created by using [MI_Application_NewDestinationOptions](https://learn.microsoft.com/previous-versions/windows/desktop/api/mi/nf-mi-mi_application_newdestinationoptions). See [MI_DestinationOptions_Delete](https://learn.microsoft.com/previous-versions/windows/desktop/api/mi/nf-mi-mi_destinationoptions_delete).

### `GetCredentialsAt`

Get the credentials at the specified index. See [MI_DestinationOptions_GetCredentialsAt](https://learn.microsoft.com/previous-versions/windows/desktop/api/mi/nf-mi-mi_destinationoptions_getcredentialsat).

### `GetCredentialsCount`

Gets the number of previously added credentials. See [MI_DestinationOptions_GetCredentialsCount](https://learn.microsoft.com/previous-versions/windows/desktop/api/mi/nf-mi-mi_destinationoptions_getcredentialscount).

### `GetCredentialsPasswordAt`

Gets a credentials password based on a specified index. See [MI_DestinationOptions_GetCredentialsPasswordAt](https://learn.microsoft.com/previous-versions/windows/desktop/api/mi/nf-mi-mi_destinationoptions_getcredentialspasswordat).

### `GetNumber`

Gets a previously added custom number option. See [MI_DestinationOptions_GetNumber](https://learn.microsoft.com/previous-versions/windows/desktop/api/mi/nf-mi-mi_destinationoptions_getnumber).

### `GetOption`

Gets a previously added option value based on the option name. See [MI_DestinationOptions_GetOption](https://learn.microsoft.com/previous-versions/windows/desktop/api/mi/nf-mi-mi_destinationoptions_getoption).

### `GetOptionAt`

Gets a previously added option value based on the specified index. See [MI_DestinationOptions_GetOptionAt](https://learn.microsoft.com/previous-versions/windows/desktop/api/mi/nf-mi-mi_destinationoptions_getoptionat).

### `GetOptionCount`

Gets the number of options previously added. See [MI_DestinationOptions_GetOptionCount](https://learn.microsoft.com/previous-versions/windows/desktop/api/mi/nf-mi-mi_destinationoptions_getoptioncount).

### `GetString`

Gets a previously added custom string option. See [MI_DestinationOptions_GetString](https://learn.microsoft.com/previous-versions/windows/desktop/api/mi/nf-mi-mi_destinationoptions_getstring).

### `SetNumber`

Sets a custom numeric option value. See [MI_DestinationOptions_SetNumber](https://learn.microsoft.com/previous-versions/windows/desktop/api/mi/nf-mi-mi_destinationoptions_setnumber).

### `SetString`

Sets a custom string option. See [MI_DestinationOptions_SetString](https://learn.microsoft.com/previous-versions/windows/desktop/api/mi/nf-mi-mi_destinationoptions_setstring).

### `SetInterval`

TBD

### `GetInterval`

TBD