# WSD_SOAP_FAULT structure

## Description

Represents a generated SOAP fault.

## Members

### `Code`

A [WSD_SOAP_FAULT_CODE](https://learn.microsoft.com/windows/desktop/api/wsdtypes/ns-wsdtypes-wsd_soap_fault_code) structure that contains a SOAP fault code.

### `Reason`

A [WSD_SOAP_FAULT_REASON](https://learn.microsoft.com/windows/desktop/api/wsdtypes/ns-wsdtypes-wsd_soap_fault_reason) structure that contains localized human readable explanations of the fault.

### `Node`

The SOAP node on the SOAP message path that caused the fault.

### `Role`

The SOAP role in which the **Node** was acting at the time the fault occurred.

### `Detail`

A [WSDXML_ELEMENT](https://learn.microsoft.com/windows/desktop/api/wsdxmldom/ns-wsdxmldom-wsdxml_element) structure that contains application-specific error information pertaining to the fault.

## See also

[WSDGenerateFault](https://learn.microsoft.com/windows/desktop/api/wsdutil/nf-wsdutil-wsdgeneratefault)

[WSDGenerateFaultEx](https://learn.microsoft.com/windows/desktop/api/wsdutil/nf-wsdutil-wsdgeneratefaultex)