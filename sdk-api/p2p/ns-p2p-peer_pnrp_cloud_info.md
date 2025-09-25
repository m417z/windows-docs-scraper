# PEER_PNRP_CLOUD_INFO structure

## Description

The **PEER_PNRP_CLOUD_INFO** structure contains information about a Peer Name Resolution Protocol (PNRP) cloud.

## Members

### `pwzCloudName`

Pointer to a zero-terminated Unicode string that contains the name of the PNRP cloud. The maximum size of this name is 256 characters.

### `dwScope`

Constant value that specifies the network scope of the PNRP cloud.

| Value | Meaning |
| --- | --- |
| **PNRP_SCOPE_ANY**<br><br>0 | All IP addresses are allowed to register with the PNRP cloud. |
| **PNRP_GLOBAL_SCOPE**<br><br>1 | The scope is global; all valid IP addresses are allowed to register with the PNRP cloud. |
| **PNRP_SITE_LOCAL_SCOPE**<br><br>2 | The scope is site-local; only IP addresses defined for the site are allowed to register with the PNRP cloud. |
| **PNRP_LINK_LOCAL_SCOPE**<br><br>3 | The scope is link-local; only IP addresses defined for the local area network are allowed to register with the PNRP cloud. |

### `dwScopeId`

The ID of a specific IP address scope defined for the PNRP cloud.