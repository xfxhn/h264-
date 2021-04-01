#pragma once
#include "Common.h"
#include "NaluType.h"
#include "ParseSPS.h"
#include "ParsePPS.h"
#include "ParseSlice.h"
#pragma warning(disable:4996)


class AnnexBReader
{
public:
	AnnexBReader();

	bool open(const char* filePath);
	bool close();
	int ReadNalu(uint8_t* buffer, rsize_t& dataLen);

	//ȥ���������ֽ�
	size_t unescape(uint8_t* src, uint32_t src_len);
	~AnnexBReader();
private:
	/*ParsePPS* pps;
	ParseSPS* sps;*/
	ParseSlice* slice;


	//��ʶ������ͷ���ᵽ��ͼ������������� pic_parameter_set_id ��ֵӦ���� 0 ��  255 �� ��Χ�ڣ�����0 ��255����
	ParsePPS ppsCache[256];
	//����ʶ��ͼ���������ָ�����в�������seq_parameter_set_id ��ֵӦ�� 0-31 �ķ�Χ �ڣ�����0 ��31��
	ParseSPS spsCache[32];

	/*vector<ParsePPS*> ppsCache;
	
	vector<ParseSPS*> spsCache;*/
private:
	static const int MAX_BUFFER_SIZE;
	bool CheckStartCode(int& startCodeLen, uint8_t* bufPtr, int bufLen);


	void getNaluHeader(uint8_t* buffer,int size);
	

	FILE* f = nullptr;

	//ʹ��typedef����ṹ��ͬʱ����_NaluUnit�ṹ�����NaluUnit����������ɲ���ʹ��struct data��ֱ��ʹ��DATA����
};



