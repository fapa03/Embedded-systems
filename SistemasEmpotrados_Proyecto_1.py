import pymysql
import serial
ser = serial.Serial ('COM23',9600)
try:
    
    while True:
        datos = ser.readline()
        dat = datos.decode("utf-8",errors = "ignore")
        print(dat)
        con= pymysql.connect(host="localhost",user="root",
                               password="",database="incubadora_sistemasempotrados")
        sql= 'insert into sensor_data  (Id_Sensor,valor,Fecha) values(%s,now())' % dat 
        cursor= con.cursor()
        cursor.execute(sql)
        con.commit()
finally: 
    ser.close()