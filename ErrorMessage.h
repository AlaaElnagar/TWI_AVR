/*
 * ErrorMessage.h
 *
 *  Created on: ??ş/??ş/????
 *      Author: alaqsa
 */

#ifndef ERRORMESSAGE_H_
#define ERRORMESSAGE_H_

typedef enum Message {
	/*Master meassages*/
	TWI_MStart_ok,											/*0*/
	TWI_MStart_nok,                                         /*1*/
	TWI_M_Restart_Ok,                             /*2*/
	TWI_M_Restart_Nok,                            /*3*/
	TWI_MS_SLA_w_Ok,                          /*4*/
	TWI_MS_SLA_w_Nok,                         /*5*/
	TWI_MS_Data_Ok,                                  /*6*/
	TWI_MS_Data_Nok,                                 /*7*/
	TWI_MR_Data_Ok,                               /*8*/
	TWI_MR_Data_Nok,                              /*9*/
	TWI_MS_SLA_R_Ok,                          /*10*/
	TWI_MS_SLA_R_Nok,                         /*11*/

	/*Slave meassages*/

	TWI_SS_Data_Ok,                                    /*12*/
	TWI_SS_Data_Nok,                                   /*13*/
	TWI_SR_Data_Ok,                                 /*14*/
	TWI_SR_Data_Nok,                                /*15*/
	TWI_SR_Address_Ok,                              /*16*/
	TWI_SR_Address_Nok,                              /*17*/

	TWI_SC_Add_Ok,                              /*18*/
	TWI_SC_Add_Nok                              /*19*/


}Enu_messeage;


/*prescaling values*/
typedef enum Prescaller_enuState{

	PrescalerOne=1,
	PrescalerFour=4,
	PrescalerSixteen=60,
	PrescalerSixtyFour=64

}prescaller_enuState;

/*The avialable addresses */

typedef enum addresses{

Address_1_Set           =    1			,
Address_2_Set           =    2          ,
Address_3_Set           =    3          ,
Address_4_Set           =    4          ,
Address_5_Set           =    5          ,
Address_6_Set           =    6          ,
Address_7_Set           =    7          ,
Address_8_Set           =    8          ,
Address_9_Set           =    9          ,
Address_10_Set          =    10          ,
Address_11_Set          =    11          ,
Address_12_Set          =    12          ,
Address_13_Set          =    13          ,
Address_14_Set          =    14          ,
Address_15_Set          =    15          ,
Address_16_Set          =    16          ,
Address_17_Set          =    17          ,
Address_18_Set          =    18          ,
Address_19_Set          =    19          ,
Address_20_Set          =    20          ,
Address_21_Set          =    21          ,
Address_22_Set          =    22          ,
Address_23_Set          =    23          ,
Address_24_Set          =    24          ,
Address_25_Set          =    25          ,
Address_26_Set          =    26          ,
Address_27_Set          =    27          ,
Address_28_Set          =    28          ,
Address_29_Set          =    29          ,
Address_30_Set          =    30          ,
Address_31_Set          =    31          ,
Address_32_Set          =    32          ,
Address_33_Set          =    33          ,
Address_34_Set          =    34          ,
Address_35_Set          =    35          ,
Address_36_Set          =    36          ,
Address_37_Set          =    37          ,
Address_38_Set          =    38          ,
Address_39_Set          =    39          ,
Address_40_Set          =    40          ,
Address_41_Set          =    41          ,
Address_42_Set          =    42          ,
Address_43_Set          =    43          ,
Address_44_Set          =    44          ,
Address_45_Set          =    45          ,
Address_46_Set          =    46          ,
Address_47_Set          =    47          ,
Address_48_Set          =    48          ,
Address_49_Set          =    49          ,
Address_50_Set          =    50          ,
Address_51_Set          =    51          ,
Address_52_Set          =    52          ,
Address_53_Set          =    53          ,
Address_54_Set          =    54          ,
Address_55_Set          =    55          ,
Address_56_Set          =    56          ,
Address_57_Set          =    57          ,
Address_58_Set          =    58          ,
Address_59_Set          =    59          ,
Address_60_Set          =    60          ,
Address_61_Set          =    61          ,
Address_62_Set          =    62          ,
Address_63_Set          =    63          ,
Address_64_Set          =    64          ,
Address_65_Set          =    65          ,
Address_66_Set          =    66          ,
Address_67_Set          =    67          ,
Address_68_Set          =    68          ,
Address_69_Set          =    69          ,
Address_70_Set          =    70          ,
Address_71_Set          =    71          ,
Address_72_Set          =    72          ,
Address_73_Set          =    73          ,
Address_74_Set          =    74          ,
Address_75_Set          =    75          ,
Address_76_Set          =    76          ,
Address_77_Set          =    77          ,
Address_78_Set          =    78          ,
Address_79_Set          =    79          ,
Address_80_Set          =    80          ,
Address_81_Set          =    81          ,
Address_82_Set          =    82          ,
Address_83_Set          =    83          ,
Address_84_Set          =    84          ,
Address_85_Set          =    85          ,
Address_86_Set          =    86          ,
Address_87_Set          =    87          ,
Address_88_Set          =    88          ,
Address_89_Set          =    89          ,
Address_90_Set          =    90          ,
Address_91_Set          =    91          ,
Address_92_Set          =    92          ,
Address_93_Set          =    93          ,
Address_94_Set          =    94          ,
Address_95_Set          =    95          ,
Address_96_Set          =    96          ,
Address_97_Set          =    97          ,
Address_98_Set          =    98          ,
Address_99_Set          =    99          ,
Address_100_Set         = 100           ,
Address_101_Set         = 101           ,
Address_102_Set         = 102           ,
Address_103_Set         = 103           ,
Address_104_Set         = 104           ,
Address_105_Set         = 105           ,
Address_106_Set         = 106           ,
Address_107_Set         = 107           ,
Address_108_Set         = 108           ,
Address_109_Set         = 109           ,
Address_110_Set         = 110           ,
Address_111_Set         = 111           ,
Address_112_Set         = 112           ,
Address_113_Set         = 113           ,
Address_114_Set         = 114           ,
Address_115_Set         = 115           ,
Address_116_Set         = 116           ,
Address_117_Set         = 117           ,
Address_118_Set         = 118           ,
Address_119_Set         = 119           ,
Address_120_Set         = 120           ,
Address_121_Set         = 121           ,
Address_122_Set         = 122           ,
Address_123_Set         = 123           ,
Address_124_Set         = 124           ,
Address_125_Set         = 125           ,
Address_126_Set         = 126           ,
Address_127_Set         = 127

}TWI_enuAddress;





#endif /* ERRORMESSAGE_H_ */
