# IPSEC_SA_IDLE_TIMEOUT0 structure

## Description

The **IPSEC_SA_IDLE_TIMEOUT0** structure specifies the security association (SA) idle timeout in IPsec policy.

## Members

### `idleTimeoutSeconds`

Specifies the amount of time in seconds after which IPsec SAs should become idle.

### `idleTimeoutSecondsFailOver`

Specifies the amount of time in seconds after which IPsec SAs should become idle if the peer machine supports fail over.

## Remarks

**IPSEC_SA_IDLE_TIMEOUT0** is a specific implementation of IPSEC_SA_IDLE_TIMEOUT. See [WFP Version-Independent Names and Targeting Specific Versions of Windows](https://learn.microsoft.com/windows/desktop/FWP/wfp-version-independent-names-and-targeting-specific-versions-of-windows) for more information.