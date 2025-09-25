# TCI_CLIENT_FUNC_LIST structure

## Description

The
**TCI_CLIENT_FUNC_LIST** structure is used by the traffic control interface to register and then access client-callback functions. Each member of
**TCI_CLIENT_FUNC_LIST** is a pointer to the client provided–callback function.

## Members

### `ClNotifyHandler`

Pointer to the client-callback function
[ClNotifyHandler](https://learn.microsoft.com/previous-versions/windows/desktop/api/traffic/nc-traffic-tci_notify_handler).

### `ClAddFlowCompleteHandler`

Pointer to the client-callback function [ClAddFlowComplete](https://learn.microsoft.com/previous-versions/windows/desktop/api/traffic/nc-traffic-tci_add_flow_complete_handler).

### `ClModifyFlowCompleteHandler`

Pointer to the client-callback function [ClModifyFlowComplete](https://learn.microsoft.com/previous-versions/windows/desktop/api/traffic/nc-traffic-tci_mod_flow_complete_handler).

### `ClDeleteFlowCompleteHandler`

Pointer to the client-callback function [ClDeleteFlowComplete](https://learn.microsoft.com/previous-versions/windows/desktop/api/traffic/nc-traffic-tci_del_flow_complete_handler).

## Remarks

Any member of the
**TCI_CLIENT_FUNC_LIST** structure can be **NULL** except **ClNotifyHandler**.

## See also

[ClAddFlowComplete](https://learn.microsoft.com/previous-versions/windows/desktop/api/traffic/nc-traffic-tci_add_flow_complete_handler)

[ClDeleteFlowComplete](https://learn.microsoft.com/previous-versions/windows/desktop/api/traffic/nc-traffic-tci_del_flow_complete_handler)

[ClModifyFlowComplete](https://learn.microsoft.com/previous-versions/windows/desktop/api/traffic/nc-traffic-tci_mod_flow_complete_handler)

[ClNotifyHandler](https://learn.microsoft.com/previous-versions/windows/desktop/api/traffic/nc-traffic-tci_notify_handler)