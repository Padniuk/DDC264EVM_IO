/**
 * Acquisition library for the DDC264 Evaluation Module
 * https://www.ti.com/tool/DDC264EVM
 *
 * Author: Miguel Risco-Castillo
 * Version: 3.3
 * Date: 2024/02/27
 *
 * LICENSE: MIT License.
 * 
 * Based on code examples published by Texas Instruments at USB_IO_FOR_VB6_API.
 */
 
// The following ifdef block is the standard way of creating macros which make exporting 
// from a DLL simpler. All files within this DLL are compiled with the DDC264EVM_IO_EXPORTS
// symbol defined on the command line. this symbol should not be defined on any project
// that uses this DLL. This way any other project whose source files include this file see 
// DDC264EVM_IO_API functions as being imported from a DLL, wheras this DLL sees symbols
// defined with this macro as being exported.
#ifdef DDC264EVM_IO_EXPORTS
  #define DDC264EVM_IO_API __declspec(dllexport)
#else
  #define DDC264EVM_IO_API __declspec(dllimport)
#endif

typedef unsigned char byte;

extern DDC264EVM_IO_API int nDDC264EVM_IO;


DDC264EVM_IO_API int __stdcall ReadDeviceDescriptors(int *USBdevCount, int *bLengthPass, int *bDescriptorTypePass,
                                    long *bcdUSBPass, int *bDeviceClass, int *bDeviceSubClass,
                                    int *bDeviceProtocol, int *bMaxPacketSize0, long *idVendor,
                                    long *idProduct, long *bcdDevice, int *iManufacturer,
                                    int *iProduct, int *iSerialNumber, int *bNumConfigurations);

DDC264EVM_IO_API int __stdcall ReadInterfaceDescriptors(	int *USBdev, int *bLengthPass, int *bDescriptorTypePass,
                                        int *bInterfaceNumberPass, int *bAlternateSettingPass, short *bNumEndpointsPass,
                                        int *bInterfaceClassPass, int *bInterfaceSubClassPass, int *bInterfaceProtocolPass,
                                        int *iInterfacePass);

DDC264EVM_IO_API int __stdcall XferDataOut(int* USBdev, unsigned char* Data, long* DataLength);

DDC264EVM_IO_API int __stdcall XferDataIn(int* USBdev, unsigned char* Data, long* DataLength);

// =============================================================================================================

DDC264EVM_IO_API void __stdcall dllID(char* text, int bufsize); // Return simple dll ID string

DDC264EVM_IO_API void __stdcall dllCprght(char* text, int bufsize); // Return simple dll ID string

DDC264EVM_IO_API int __stdcall EVM_RegDataOut(int* USBdev, int* Reg, int* Data);

DDC264EVM_IO_API bool  __stdcall EVM_ResetDDC(int* USBdev);

DDC264EVM_IO_API bool  __stdcall EVM_ClearTriggers(int* USBdev);

DDC264EVM_IO_API bool  __stdcall EVM_DataSequence(int* USBdev, byte* CFGHIGH, byte* CFGLOW);

DDC264EVM_IO_API int __stdcall EVM_RegNameTable(int RegN, char* buf, int bufsize);

DDC264EVM_IO_API long __stdcall EVM_RegsTransfer(int* USBdev, int* RegsIn, int* RegEnable, int* RegsOut = nullptr);

DDC264EVM_IO_API long __stdcall EVM_DataCap(int* USBdev, int Channels, int nDVALIDReads, int* DataArray, int* AllDataAorBfirst);

// Enhanced CFG register operations based on VB6 implementation
DDC264EVM_IO_API long __stdcall EVM_WriteCFGFast(int* USBdev, byte* CFGHIGH, byte* CFGLOW, int* VerifyResults = nullptr);

DDC264EVM_IO_API bool __stdcall EVM_ReadCFGRegister(int* USBdev, byte* ReadCFGHIGH, byte* ReadCFGLOW);
