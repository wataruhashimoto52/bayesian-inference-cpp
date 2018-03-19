#coding: utf-8

import os, sys, codecs 
import argparse
import numpy as np 
import pandas as pd 
import matplotlib.pyplot as plt 

if __name__ == "__main__":
    
    parser = argparse.ArgumentParser()
    parser.add_argument('plot_txt')
    args = parser.parse_args()

    file = open(args.plot_txt, 'r').readline()
    file = file.split("\t")[:-1]
    file = map(float, file)
    file = list(file)

    plt.hist(file, bins=50)
    plt.show()