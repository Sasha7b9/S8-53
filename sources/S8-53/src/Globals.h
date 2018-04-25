#pragma once
#include "Panel/Controls.h"
#include "Settings/SettingsTypes.h"
#include "Settings/SettingsChannel.h"
#include "Settings/SettingsTime.h"
#include <stm32f2xx_hal_def.h>
#include "stm32f2xx_hal_conf.h"
#include <stm32f2xx_hal_hcd.h>
#include <stm32f2xx_hal_pcd.h>
#include <stm32f2xx_hal_dma.h>
#include <stm32f2xx_hal_spi.h>
#include <stm32f2xx_hal_adc.h>
#include <stm32f2xx_hal_dac.h>
#include <usbd_def.h>
#include <usbh_def.h>


extern USBH_HandleTypeDef handleUSBH;
extern HCD_HandleTypeDef handleHCD;
extern SPI_HandleTypeDef handleSPI;
extern ADC_HandleTypeDef handleADC;
extern DAC_HandleTypeDef handleDAC;


#define SETTINGS_IS_LOADED       (gBF.settingsLoaded)
#define NEED_OPEN_FILE_MANAGER   (gBF.needOpenFileMananger)
#define CLIENT_LAN_IS_CONNECTED  (gBF.clientLANisConnected)
#define CABLE_LAN_IS_CONNECTED   (gBF.cableLANisConnected)
#define FLASH_DRIVE_IS_CONNECTED (gBF.flashDriveIsConnected)
#define NEED_CLOSE_PAGE_SB       (gBF.needClosePageSB)
#define AUTO_FIND_IN_PROGRESS    (gBF.FPGAautoFindInProgress)
#define NEED_RESET_SETTINGS      (gBF.needResetSettings)
#define NEED_FINISH_REDRAW       (gBF.needFinishDraw)
#define SHOW_LEVEL_RSHIFT_0      (gBF.showLevelRShift0)
#define SHOW_LEVEL_RSHIFT_1      (gBF.showLevelRShift1)
#define SHOW_LEVEL_TRIGLEV       (gBF.showLevelTrigLev)
#define NUM_DRAWING_SIGNALS      (gBF.numDrawingSignals)
#define TRIG_ENABLE              (gBF.trigEnable)


typedef struct
{
    // Ethernet
    uint ethTimeLastEthifInput      : 32;   // ����� ���������� ����� � ��������� ethernetif.c:ethernetif_input() ������������ ��� ����������� ����, 
                                            // ��� ������ ethernet ���������. ��������������� ����� � ������� ��������� ������ �����������
    uint cableLANisConnected        : 1;    // ���� 1, ������, ������ ��������� ������
    uint clientLANisConnected       : 1;    // ���� 1, �� ����������� ������

    // ��� ��������� : Display::c
    uint showLevelRShift0           : 1;    // ����� �� �������� �������������� ����� ������ �������� ������� ������
    uint showLevelRShift1           : 1;
    uint showLevelTrigLev           : 1;    // ����� �� �������� �������������� ����� ������ �������� ������ �������������
    uint trigEnable                 : 1;
    uint drawRShiftMarkers          : 1;
    uint needFinishDraw             : 1;    // ���� 1, �� ������� ��������� � �����������
    uint framesElapsed              : 1;
    uint numDrawingSignals          : 8;    // ����� ������������ �������� ��� ������ ����������

    // FPGA
    uint FPGAtrigAutoFind           : 1;    // ������������� � 1 �������� ��������, ��� ����� ����������� �������������� ����� �������������, ���� 
                                            // ������� ��������������� ���������.
    uint FPGAautoFindInProgress     : 1;
    uint FPGAtemporaryPause         : 1;
    uint FPGAinProcessingOfRead     : 1;
    uint FPGAcanReadData            : 1;
    uint FPGAcritiacalSituation     : 1;
    uint FPGAfirstAfterWrite        : 1;    // ������������ � ������ �������������. ����� ������ ������ ��������� � �������
                                            // ����� �� ������������ ������ ��������� ������ � ���, ������ ��� ��� �������� � ������ ������

    // ����
    uint soundIsBeep                : 1;
    uint soundWarnIsBeep            : 1;
    uint buttonIsPressed            : 1;    // ����� ����������� ���� ������� ������, ��������������� ���� ����, ����� �����, ����������� �� ���� 
                                            // ����������

    // ������
    uint panelIsRunning             : 1;
    
    // Governor
    uint inMoveIncrease             : 1;
    uint inMoveDecrease             : 1;
    uint addressGovernor            : 32;
    uint timeStartMS                : 32;

    // VCP
    uint cableVCPisConnected        : 1;
    uint connectToHost              : 1;

    // Flash drive
    uint flashDriveIsConnected      : 1;
    uint cursorInDirs               : 1;    // ���� 1, �� ����� ��������� ���������� �� ���������
    uint needRedrawFileManager      : 2;    // ���� 1, �� ����-�������� ��������� � ������ �����������
                                            // ���� 2, �� ������������ ������ ��������
                                            // ���� 3, �� ������������ ������ �����

    uint settingsLoaded             : 1;    // ��� ���������� ����� ��� ����, ����� ��������� ������ ������ ������ �������� ��-�� ������������� 
                                            // ��������� ������� (��� ����������� �� ����� ����������� ��������� ������ ������ �� ������ ���������� 
                                            // ������� �������� �������, ��� ��������� �������� ��������� ���������).
    uint showHelpHints              : 1;    // ���� 1, �� ��� ������� ������ ������ ���������� � ������ ��������� ��������� � � ����������

    uint showDebugMenu              : 1;
    
    uint tuneTime                   : 1;    // ���� 1, �� ����� �������� �������� ����� ������� �������� ��������� �������� �������

    int topMeasures                 : 9;    // ���� ������� ������ ���������. ��� �������� ����� ��� ����������� ������ ��������� �� ����� - ����� 
                                            // ��� ������ �� �����������
    uint needOpenFileMananger       : 1;    // ���� 1, �� ����� ������� �������� �������� (��������� ���������������)
    uint needClosePageSB            : 1;    // ���� 1, ����� ��������� �������� ����� ������
    uint needResetSettings          : 1;    // ���� 1, �� ��������� ����� ��������
} BitField;


extern BitField gBF;

#define CURRENT_NUM_LATEST_SIGNAL       (gMemory.currentNumLatestSignal)
#define CURRENT_NUM_INT_SIGNAL          (gMemory.currentNumIntSignal)
#define EXIT_FROM_INT_TO_LAST           (gMemory.exitFromIntToLast)
#define RUN_FPGA_AFTER_SMALL_BUTTONS    (gMemory.runningFPGAbeforeSmallButtons)
#define INT_SHOW_ALWAYS                 (gMemory.showAlways)
#define NEED_SAVE_TO_DRIVE              (gMemory.needForSaveToFlashDrive)

#define EXIT_FROM_SET_NAME_TO           (gMemory.exitFromModeSetNameTo)
#define RETURN_TO_MAIN_MENU             0
#define RETURN_TO_LAST_MEM              1
#define RETURN_TO_INT_MEM               2
#define RETURN_TO_DISABLE_MENU          3
#define EXIT_FROM_SET_NAME_TO_MAIN_MENU (EXIT_FROM_SET_NAME_TO == RETURN_TO_MAIN_MENU)
#define EXIT_FROM_SET_NAME_TO_LAST      (EXIT_FROM_SET_NAME_TO == RETURN_TO_LAST_MEM)
#define EXIT_FROM_SET_NAME_TO_INT       (EXIT_FROM_SET_NAME_TO == RETURN_TO_INT_MEM)
#define EXIT_FROM_SET_NAME_TO_DIS_MENU  (EXIT_FROM_SET_NAME_TO == RETURN_TO_DISABLE_MENU)

typedef struct 
{
    int16   currentNumLatestSignal;                 // ������� ����� ���������� ������� � ������ ������ - ���������
    int8    currentNumIntSignal;                    // ������� ����� �������, ������������ � ����
    uint    showAlways                      : 1;    // ���� 1, �� ���������� ������ ��������� � ������ "�����. ��" ������
    uint    runningFPGAbeforeSmallButtons   : 1;    // ����� ����������� ���������� � ���, �������� �� ���� ����� ��������� � ����� ������ � �������
    uint    exitFromIntToLast               : 1;    // ���� 1, �� �������� �� �������� ���������� ������ ����� �� ����������, � � ���� ���������
    uint    exitFromModeSetNameTo           : 2;    // ���� ������������ �� ���� ��������� ����� ��� ���������� : 0 - � �������� ����, 1 - � ���� 
                                                    // ���������, 2 - � ���� ����� ��, 3 - � ������� ���� � ����������� ����
    uint    needForSaveToFlashDrive         : 1;    // ���� 1, �� ����� ��������� ����� ��������� �� ������.
} GMemory;


extern GMemory gMemory;


typedef enum
{
    StateCalibration_None,
    StateCalibration_ADCinProgress,
    StateCalibration_RShift0start,
    StateCalibration_RShift0inProgress,
    StateCalibration_RShift1start,
    StateCalibration_RShift1inProgress,
    StateCalibration_ErrorCalibration0,
    StateCalibration_ErrorCalibration1
} StateCalibration;

typedef enum
{
    StateWorkFPGA_Stop,                             // ���� - �� ���������� ����������� ����������.
    StateWorkFPGA_Wait,                             // ��� ����������� ��������������.
    StateWorkFPGA_Work,                             // ��� ������.
    StateWorkFPGA_Pause                             // ��� ���������, ����� �������� ������������� ������, ��������, ��� ������ ������ ��� ��� 
                                                    // ������ �������� ���������.
} StateWorkFPGA;


typedef struct
{
    bool needCalibration;				        // ������������� � true �������� ��������, ��� ���������� ���������� ����������.
    StateWorkFPGA stateWorkBeforeCalibration;
    StateCalibration stateCalibration;          // ������� ��������� ����������. ������������ � �������� ����������.
} StateFPGA;

typedef struct
{
    uint hours : 5;
    uint minutes : 6;
    uint seconds : 6;
    uint year : 7;
    uint month : 4;
    uint day : 5;
} PackedTime;

typedef struct
{
    void*       addrNext;               // ����� ��������� ������.
    void*       addrPrev;               // ����� ���������� ������.
    uint        rShiftCh0       : 10;   // �������� �� ����������
    uint        rShiftCh1       : 10;
    uint        trigLevCh0      : 10;   // ������� �������������
    int16       tShift;                 // �������� �� �������
    ModeCouple  modeCouple1     : 2;
    Range       range[2];               // ������� �� ���������� ����� �������.

    uint        trigLevCh1      : 10;
    uint        length1channel  : 11;   // ������� �������� � ������ ����� ��������� ������ ������
    TBase       tBase           : 5;    // ������� �� �������
    ModeCouple  modeCouple0     : 2;    // ����� ������ �� �����
    uint        peakDet         : 2;    // ������� �� ������� ��������
    uint        enableCh0       : 1;    // ������� �� ����� 0
    uint        enableCh1       : 1;    // ������� �� ����� 1

    uint        inverseCh0      : 1;
    uint        inverseCh1      : 1;
    Divider  multiplier0     : 1;
    Divider  multiplier1     : 1;
    PackedTime  time;
} DataSettings;


extern const char *gStringForHint;  // ������ ���������, ������� ���� �������� � ������ ����������� ������ ���������.
extern void* gItemHint;              // Item, ��������� ��� �������� ����� �������� � ������ ����������� ������ ���������.

void SetItemForHint(void *item);

extern StateFPGA gStateFPGA;

extern uint8        *gData0;    // ��������� �� ������ ������� ������, ������� ���� �������� �� ������
extern uint8        *gData1;    // ��������� �� ������ ������� ������, ������� ���� �������� �� ������
extern DataSettings *gDSet;     // ��������� �� ��������� �������� ��������

extern DataSettings *gDSmemInt;       //--
extern uint8        *gData0memInt;    // | ����� ������ �� ����, ������� ������ ���������� �� �����
extern uint8        *gData1memInt;    //-/

extern DataSettings *gDSmemLast;
extern uint8        *gData0memLast;
extern uint8        *gData1memLast;

extern void *extraMEM;      // ��� ����������� ���������. ������������ ��� ��������� ������ ����������, ������� �� ����� �� ����� ��������� ���������,
                            // �� ����� ������ ��� � ����� �������. ����� �������������� � ������� ������ malloc() ���������� ����������� ����������
                            // ������, ������� ����� ������������� ������ free()

#define MALLOC_EXTRAMEM(NameStruct, name)   extraMEM = malloc(sizeof(NameStruct));    \
                                            NameStruct *name = (NameStruct*)extraMEM
#define ACCESS_EXTRAMEM(NameStruct, name)   NameStruct *name = (NameStruct*)extraMEM
#define FREE_EXTRAMEM()                     free(extraMEM)

extern int transmitBytes;
