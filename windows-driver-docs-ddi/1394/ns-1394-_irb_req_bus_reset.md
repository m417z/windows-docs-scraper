# _IRB_REQ_BUS_RESET structure

## Description

This structure contains the fields necessary for the 1394 bus driver to create a bus reset request.

## Members

### `fulFlags`

Set this flag to BUS_RESET_FLAGS_FORCE_ROOT to make the local node the root node. All other values indicate that the node is not root.