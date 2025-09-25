# TAPIOBJECT_EVENT enumeration

## Description

The
**TAPIOBJECT_EVENT** enum describes TAPI object events. The
[ITTAPIObjectEvent::get_Event](https://learn.microsoft.com/windows/desktop/api/tapi3if/nf-tapi3if-ittapiobjectevent-get_event) method returns a member of this enum to indicate the type of TAPI object event that occurred.

## Constants

### `TE_ADDRESSCREATE:0`

A new address has been created.

### `TE_ADDRESSREMOVE`

An address has been moved.

### `TE_REINIT`

The TAPI object has been reinitialized

### `TE_TRANSLATECHANGE`

A translation change has occurred.

### `TE_ADDRESSCLOSE`

Address has been closed.

### `TE_PHONECREATE`

### `TE_PHONEREMOVE`

## See also

[ITTAPIObjectEvent::get_Event](https://learn.microsoft.com/windows/desktop/api/tapi3if/nf-tapi3if-ittapiobjectevent-get_event)