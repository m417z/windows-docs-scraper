# WTS_SERVICE_STATE structure

## Description

Contains information about changes in the state of the Remote Desktop Services service.

## Members

### `RcmServiceState`

A value of the [WTS_RCM_SERVICE_STATE](https://learn.microsoft.com/windows/desktop/api/wtsdefs/ne-wtsdefs-wts_rcm_service_state) enumeration type that specifies whether the service is starting or stopping.

### `RcmDrainState`

A value of the [WTS_RCM_DRAIN_STATE](https://learn.microsoft.com/windows/desktop/api/wtsdefs/ne-wtsdefs-wts_rcm_drain_state) enumeration type that specifies whether the RD Session Host server is changing its drain state.

## Remarks

This structure is used by the [NotifyServiceStateChange](https://learn.microsoft.com/windows/desktop/api/wtsprotocol/nf-wtsprotocol-iwtsprotocolmanager-notifyservicestatechange) method.