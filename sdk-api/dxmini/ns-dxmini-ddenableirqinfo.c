typedef struct _DDENABLEIRQINFO {
  DWORD           dwIRQSources;
  DWORD           dwLine;
  PDX_IRQCALLBACK IRQCallback;
  PDX_IRQDATA     lpIRQData;
} DDENABLEIRQINFO, *PDDENABLEIRQINFO;